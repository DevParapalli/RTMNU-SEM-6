# Practical 03 : Lexing a File

## Aim

Write a program to read constants as a string and convert it to number.

## Test Cases

1. Decimal : +15, -5, 123
2. Octal: +0123, 0117, -0777
3. Exponential: 1.6e-19, -0/5E+2, +1.7E4

## Theory

Identifiers: `[a-zA-Z_][a-zA-Z_0-9]*\n` _According to C standard, identifiers begin with a letter or an underscore, but not with numbers_
Decimal Integers: `[+-]?[1-9][0-9]*\n|0\n`
Octal Integers: `[+-]?0[0-7]+\n` _According to C standard, octal numbers begin with a 0._
Hexadecimal Integers: `[+-]?0[xX][0-9a-fA-F]+\n`
Floating Point Numbers: `[+-]?[0-9]*\.?[0-9]+\n`
Exponential Numbers: `[+-]?[0-9]*\.?[0-9]+([eE][+-]?[0-9]+)+\n`

Built In Functions (string.h)

1. strtof - string to float
2. strtol - string to long

User Defined Functions:

1. _strtoexp - string to exponential
2. _strtoo - string to octal
3. _strtoh - string to hexadecimal
4. _strtod - string to decimal

## Practical Files

- [3.l](./3.l)
- [input.txt](./input.txt)
- *[3.c](./3.c) _Used to develop functions for use in 3.l_
- @[printed_output.txt](./printed_output.pdf)

`flex 3.l && gcc lex.yy.c -o 3.exe && ./3.exe input.txt`
