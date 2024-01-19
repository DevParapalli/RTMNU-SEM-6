# Compiler Design

## Tools Required

- Flex: <https://gnuwin32.sourceforge.net/packages/flex.htm>
- Bison: <https://gnuwin32.sourceforge.net/packages/bison.htm>

## Usage instructions

add `%option noyywrap` at top of flex file

- only flex
  - `flex <filename>.l`
  - `gcc lex.yy.c -lfl`
  - `./a.exe`
- flex and bison
  - `flex <filename>.l`
  - `bison -d <filename>.y`
  - `gcc lex.yy.c <filename>.tab.c -lfl`


## Practical List

1. [Write a lex program to recognize valid strings using regular expression: `(a|b)*abb`](./Practical%2001/README.md)
2. [Practical 02](./Practical%2002/README.md)
