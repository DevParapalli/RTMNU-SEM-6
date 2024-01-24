# Practical 03 : Lexing a File

## Aim

Write a program to read constants as a string and convert it to number.

## Test Cases

1. Decimal : +15, -5, 123
2. Octal: +0123, 0117, -0777
3. Exponential: 1.6e-19, -0/5E+2, +1.7E4

## Theory

## Practical Files

- [3.l](./3.l)
- [input.txt](./input.txt)
- *[3.c](./3.c) _Used to develop functions for use in 3.l_
- @[printed_output.txt](./printed_output.pdf)

`flex 3.l && gcc lex.yy.c -o 3.exe && ./3.exe input.txt`
