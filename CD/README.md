# Compiler Design

## [Notes](./NOTES.md)

## Tools Required

- Flex: <https://gnuwin32.sourceforge.net/packages/flex.htm>
- Bison: <https://gnuwin32.sourceforge.net/packages/bison.htm>

## Usage instructions

add `%option noyywrap` at top of flex file
`noyywrap` terminates lex after EOF of 1 file has been reached

- only flex
  - `flex <filename>.l`
  - `gcc lex.yy.c -lfl`
  - `./a.exe`
- flex and bison
  - `flex <filename>.l`
  - `bison -d <filename>.y`
  - `gcc lex.yy.c <filename>.tab.c -lfl`

- templated lex file : [template.l](./template.l)

## Practical List

1. [Write a lex program to recognize valid strings using regular expression: `(a|b)*abb`](./Practical%2001/)
2. [Write a lex program to recognize tokens](./Practical%2002/)
3. [Write program to read lines from a file and analyze it lexically](./Practical%2003/)
4. [Write a C program to eliminate left recursion from grammar](./Practical%2004/)
5. [Design recursive descent parser for grammar `E:+EE|-EE|a|b`](./Practical%2005/)

## Useful Links

- <http://alumni.cs.ucr.edu/~lgao/teaching/bison.html>

## Practical Files

- [Index Format.pdf](./Index%20Format.pdf)
