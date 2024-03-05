/**
* @file LightMeter_web.cpp
* @brief Demonstrate how to use Cloud services with a simple example of Light Meter
*
* 1. Reads the light value from the light sensor(connected to A0)
* 2. The cloud based on a rule sends buzzer actuations 0 or 1
* 3. If buzzer actuation value is 1 (meaning low light)
*     a. sound the buzzer connected to Galileo(connected to D5)
*     b. Display DARK on the LCD display(connected to I2C)
* 4. If buzzer actuation value is 0 (meaning bright light)
*     a. Stop the buzzer
*     b. Display BRIGHT on the LCD display
*
* @note grovebuzzer needs to be connected to the Galileo Arduino via base
* shield at D5.
* @note grovelight sensor needs to be connected to the Galileo Arduino via base
* shield analog port A0
* @note Grove LCD RGB Backlight module needs to be connected to Galileo Arduino
*  via base shield's I2C port.
* @note Grove LCD needs 5V to operate normally, ensure Grove shield switch
* is set to 5V
*
* @note Additional linker flags: "upm-grove", "upm-buzzer", "upm-i2clcd", "paho-mqtt3c"
*
* @see http://iotdk.intel.com/docs/master/upm/
* @see https://ubidots.com/
* @see https://ubidots.com/docs/api/index.html#mqtt-api-reference
* @see http://www.eclipse.org/paho
*
* @bug No known bugs
*
*/
/* -- Includes -- */


#include "mraa.hpp"

extern "C" {
/* MQTT library includes */
#include "MQTTClient.h"
}

#include "stdlib.h"

#include <iostream>
#include <unistd.h>
#include <signal.h>

/* UPM library includes */
#include "grove.h"
/* LCD library includes */
#include <jhd1313m1.h>
/* buzzer library includes */
#include "buzzer.h"

/* Macro definitions for cloud functionality. Refer to MQTT API reference section for details */

// Important: Please fill out below commented values from your own ubidot account
#define MESSAGE_TOPIC "/v1.6/devices/Light_meter"
#define TOPIC "/v1.6/devices/Light_meter/buzz"
const char * ubidots_username = "A1E-jNHCBjc2FXoirIsvaiOrdonQhvTaBr";

const char * ubidots_password = "";

#define HOST_PROTO "tcp://"
#define HOST_SUFFIX "things.ubidots.com:"
#define HOST_PORT "1883"
#define DUMMY_MAX_VALUE 100
#define MQTT_DEFAULT_QOS 0
#define QOS 1


MQTTClient client;

// Define file scope variable for LCD
upm::Jhd1313m1* screen;

// Define file scope variable for Buzzer
upm::Buzzer* sound;

/**
 * @brief Called when the MQTT client loses connection to the server
 * @param context A pointer to the <i>context</i> value originally passed to
 * MQTTClient_setCallbacks(), which contains any application-specific context.
 * @param cause The reason for the disconnection.
 * Currently, <i>cause</i> is always set to NULL.
 */
void connection_lost(
        void * context,
        char* cause
        )
{
    printf("Connection lost\n");
    exit(MQTTCLIENT_DISCONNECTED);
}

/**
 * @brief This function is called when a message has been successfully published
 * to the server
 *
 * <b>Note:</b>This function is not called when messages are
 * published at QoS0.
 *
 * @param context A pointer to the <i>context</i> value originally passed to
 * MQTTClient_setCallbacks(), which contains any application-specific context.
 * @param dt The ::MQTTClient_deliveryToken associated with
 * the published message. Applications can check that all messages have been
 * correctly published by matching the delivery tokens returned from calls to
 * MQTTClient_publish() and MQTTClient_publishMessage() with the tokens passed
 * to this callback..
 **/

void delivery_complete(void * context, MQTTClient_deliveryToken dt)
{
    printf("Publishing of message with token %d confirmed\n", dt);
}


/**
 * @brief This is a callback function triggered upon receipt of messages.
 *
 * The client application must provide an implementation of this function to
 * enable asynchronous receipt of messages. The function is registered with
 * the client library by passing it as an argument to MQTTClient_setCallbacks().
 * It is called by the client library when a new message that matches a client
 * subscription has been received from the server. This function is executed on
 * a separate thread to the one on which the client application is running.
 *
 * @param context A pointer to the <i>context</i> value originally passed to
 * MQTTClient_setCallbacks(), which contains any application-specific context.
 * @param topicName The topic associated with the received message.
 * @param topicLen The length of the topic if there are one
 * more NULL characters embedded in <i>topicName</i>, otherwise <i>topicLen</i>
 * is 0. If <i>topicLen</i> is 0, the value returned by <i>strlen(topicName)</i>
 * can be trusted. If <i>topicLen</i> is greater than 0, the full topic name
 * can be retrieved by accessing <i>topicName</i> as a byte array of length
 * <i>topicLen</i>.
 * @param message The MQTTClient_message structure for the received message.
 * This structure contains the message payload and attributes.
 *
 * @return This function must return a boolean value indicating whether or not
 * the message has been safely received by the client application. Returning
 * true indicates that the message has been successfully handled.
 * Returning false indicates that there was a problem. In this
 * case, the client library will reinvoke MQTTClient_messageArrived() to
 * attempt to deliver the message to the application again.
 */

int message_arrived(
        void * context,
        char * topic,
        int topic_len,
        MQTTClient_message * message
        )
{
    int i;
    char* payloadptr;
    printf("inside function message arrived\n");
    printf("Message arrived\n");
    printf("topic: %s\n", topic);
    printf("message : ");
    payloadptr = (char *)message->payload;
    for(i=0; i<(int)message->payloadlen; i++)
    {
        putchar(*payloadptr++);
    }
    putchar('\n');

    /*Since TOPIC has /../lv -> message will only contain the last value and not
    complete JSON string
    convert the string to number for getting buzzer value
    */
    int buzz = 0;
    buzz = atoi((char *)message->payload);
    printf("received buzz value : %d\n", buzz);

    //if buzz = 1, print dark in LCD, and sound Buzzer
    //if buzz = 0, print bright in LCD and turn off Buzzer


    const std::size_t color = 0x0000ff;

    std::size_t red   = (color & 0xff0000) >> 16;
    std::size_t green = (color & 0x00ff00) >> 8;
    std::size_t blue  = (color & 0x0000ff);

    std::string text1("Dark !!!");
    text1.resize(16, ' ');

    std::string text2("BRIGHT !!!");
    text1.resize(16, ' ');

    //if light value is 1, sound the buzzer and display DARK on LCD
    if(buzz == 0)
    {
        sound->playSound(5000, 1000000);
        screen->setCursor(0,0);
        screen->write(text1);
        screen->setColor(red, green, blue);
    }
    //if light value is 0, stop the buzzer and display BRIGHT on LCD
    else if(buzz == 1)
    {
        sound->stopSound();
        screen->setCursor(0,0);
        screen->write(text2);
        screen->setColor(255, 255, 255); //bright
    }

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topic);
    return true;
}
/**
 * @brief Main function does initializations, installs ISR, enters loop
 *
 * It performs following tasks:
 * 1. Confirms the target is an Intel Galileo or Edison platform
 * 2. Create a client for connecting to the Ubidots server
 * 3. Setup call backs before connecting the client to the server
 * 4. Connect the client to the server
 * 5. Subscribe to the variable
 * 6. Enter loop to read light sensor and publish to the cloud
 * 7. Stop after sending 60 values
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns mraa::SUCCESS.
 *
 */
int main()
{
    // select onboard LED pin based on the platform type
    // create a GPIO object from MRAA using it
    char host[256];
    char clientID[256];
    int count = 0;

    // check that we are running on Galileo or Edison
    mraa::Platform platform = mraa::getPlatformType();
    if ((platform != mraa::INTEL_GALILEO_GEN1) &&
            (platform != mraa::INTEL_GALILEO_GEN2) &&
            (platform != mraa::INTEL_EDISON_FAB_C)) {
        std::cerr << "Unsupported platform, exiting" << std::endl;
        return mraa::ERROR_INVALID_PLATFORM;
    }

    //Create new object of class JHD1313m1 lcd
    screen = new upm::Jhd1313m1(0, 0x3E, 0x62);

    //Create new object of class buzzer
    sound = new upm::Buzzer(5);

    // Create the light sensor object using AIO pin 0
    upm::GroveLight* light = new upm::GroveLight(0);

    snprintf(host, sizeof host, "%s%s%s", HOST_PROTO ,HOST_SUFFIX, HOST_PORT);
    snprintf(clientID, sizeof clientID, "%s", ubidots_username);
    int rc = 0;

    //create a client for connecting to the Ubidots server
    rc = MQTTClient_create(&client, const_cast<char *>(host), const_cast<char *>(clientID),
            MQTTCLIENT_PERSISTENCE_NONE, NULL);
    if (rc != MQTTCLIENT_SUCCESS) {
        std::cerr << "Failed to create MQTT client, exiting : " << rc << std::endl;
        exit(rc);
    }

    // setup call backs before connecting the client to the server
    MQTTClient_setCallbacks(client, NULL,
            &connection_lost, &message_arrived, &delivery_complete);

    MQTTClient_connectOptions data = MQTTClient_connectOptions_initializer;

    data.username = const_cast<char *>(ubidots_username);
    data.password = NULL;

    // connect the client to the server
    rc = MQTTClient_connect(client, &data);
    if (rc != MQTTCLIENT_SUCCESS) {
        std::cerr << "Failed to connect MQTT client, exiting :" << rc <<std::endl;
        exit(rc);
    }

    //subsrcibe to the variable
    rc = MQTTClient_subscribe(client, const_cast<char *>(TOPIC), MQTT_DEFAULT_QOS);
    if (rc != MQTTCLIENT_SUCCESS) {
        std::cerr << "Failed to subscribe, exiting :" << rc <<std::endl;
        exit(rc);
    }

    uint16_t light_value = 0;
    for (count=60; count>0; count --)
    {
        //Read light sensor values and publish it to cloud
        light_value = light->value();
        printf("Light Value : %d\n", light_value);
        char payload[80];
        sprintf(payload, "{ \"light\": \"%d\" }", light_value);
        int message_size = strlen(payload);

        int retained = 0;
        MQTTClient_deliveryToken dt;

        //Publish the data to the cloud
        int rc = MQTTClient_publish(client, const_cast<char *>(MESSAGE_TOPIC), message_size,
                const_cast<char *>(payload), MQTT_DEFAULT_QOS, retained, &dt);
        if (rc == MQTTCLIENT_SUCCESS)
        {
            printf("Waiting for message with token %d to be published...\n", dt);
            rc = MQTTClient_waitForCompletion(client, dt, 1000);
            if (rc == MQTTCLIENT_SUCCESS)
            {
                printf("Message with token %d published\n", dt);
            }
            else
            {
                std::cerr << "Failed to publish message with token " << dt << std::endl;
            }
        }
        else
        {
            std::cerr << "Failed to publish message with token " << dt << std::endl;
        }
        sleep(2);
    }
    printf("Stopping\n");

    int timeout = 100;
    MQTTClient_disconnect(client, timeout);
    MQTTClient_destroy(&client);
    delete sound;
    delete screen;
    delete light;

    printf("Exiting .. Bbye!\n");

    return mraa::SUCCESS;
}
