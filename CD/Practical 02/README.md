# Practical 02

## Aim

Write a lex program to recognize tokens

1. Identifiers
2. Integer Constants (Decimal, Octal, Hexadecimal)
3. Real Constants (Floating Point and Exponential)

## Test Cases

1. Integer Constant: `+15`, `-5`, `0123`, `0x1A`
2. Floating Point Constant: `+0.5`, `226.0`, `.567`, `-26.8`
3. Exponential Format: `1.6e-19`, `-0.5E+2`, `+1.7E4`, `.26e-7`

## Theory

Token Rules for the Specified Tokens:

Identifiers: `[a-zA-Z_][a-zA-Z_0-9]*\n` _According to C standard, identifiers begin with a letter or an underscore, but not with numbers_
Decimal Integers: `[+-]?[1-9][0-9]*\n`
Octal Integers: `[+-]?0[0-7]+\n` _According to C standard, octal numbers begin with a 0._
Hexadecimal Integers: `[+-]?0[xX][0-9a-fA-F]+\n`
Floating Point Numbers: `[+-]?[0-9]*\.?[0-9]+\n`
Exponential Numbers: `[+-]?[0-9]*\.?[0-9]+([eE][+-]?[0-9]+)+\n`

## Practical Files List

- [2.l](./2.l)
