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

1. [Write a lex program to recognize valid strings using regular expression: `(a|b)*abb`](./Practical%2001/)
2. [Write a lex program to recognize tokens](./Practical%2002/)
3. [Write program to read lines from a file and analyze it lexically](./Practical%2003/)
