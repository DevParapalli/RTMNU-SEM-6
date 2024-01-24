// file to test out some theories.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double _strtoexp(const char *str)
{
    double mantissa = 0;
    long exponent = 0;
    int sign = 1;
    int exp_sign = 1;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;

    mantissa = strtof(str, (char **)&str);

    if (*str == 'e' || *str == 'E')
    {
        str++;
        if (*str == '-' || *str == '+')
        {
            exp_sign = (*str++ == '-') ? -1 : 1;
            exponent = strtol(str, (char **)&str, 10);
        }
        else
        {
            exponent = strtol(str, (char **)&str, 10);
        }
    }
    else
    {
        exponent = 0;
    }

    return sign * mantissa * pow(10, exponent * exp_sign);
}

long long _strtoo(char *str)
{
    long long num = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;

    while (*str != '\0')
    {
        num = num * 8 + (*str - '0');
        str++;
    }

    return num * sign;
}

long long _strtod(char *str)
{
    long long num = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;

    while (*str != '\0')
    {
        num = num * 10 + (*str - '0');
        str++;
    }

    return num * sign;
}

long long _strtoh(char *str)
{
    long long num = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;

    if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
        str += 2;

    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
            num = num * 16 + (*str++ - '0');
        else if (*str >= 'a' && *str <= 'f')
            num = num * 16 + (*str++ - 'a' + 10);
        else if (*str >= 'A' && *str <= 'F')
            num = num * 16 + (*str++ - 'A' + 10);
    }
    return num * sign;
}

int main()
{

    char *stri = "-321";
    char *stro = "-0777";
    char *strh = "0x1ff";
    char *stre = "1.6e-19";
    char *strf = "5.4932";

    printf("%d\n", _strtod(stri));
    printf("%d\n", _strtoo(stro));
    printf("%d\n", _strtoh(strh));
    printf("%e\n", _strtoexp(stre));
    printf("%lf\n", _strtoexp(strf));

    return 0;
}