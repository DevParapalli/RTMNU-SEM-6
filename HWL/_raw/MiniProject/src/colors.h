/**
* @file colors.h
* @brief  Contains definition of global variable struct color and some specific
* color values used
*
**/
#ifndef COLORS_H_
#define COLORS_H_

struct color {
    	uint8_t r;
		uint8_t g;
		uint8_t b;
    };

    color yellow = {255, 255, 0};
    color yellowlight = {255, 255, 102};
    color red = {255, 0, 0};
    color green = {0, 255, 0};
    color blue = {0, 0, 255};


#endif /* COLORS_H_ */
