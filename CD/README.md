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
6. [Design a program for basic calculator using yacc or bison](./Practical%2006/)
7. [Write a program to evaluate postfix expression](./Practical%2007/)
8. [Practical 08, Practical 09, Practical 10](./Practical%208_9_10/)

## Useful Links

- <http://alumni.cs.ucr.edu/~lgao/teaching/bison.html>
- <https://www.cs.utexas.edu/users/novak/yaccpaper.htm> -- Check the solution for the parsing in LR 0 parsers.
- <https://codeberg.org/alifara/3-addr-generator> - 3 Address Code Generator
- <https://medium.com/@mirasma/creating-a-mini-c-compiler-using-lex-and-yacc-part-1-963b0860f5b1>
- <https://www.codeproject.com/Tips/777508/Address-Code-Generator>
- <https://cse.iitkgp.ac.in/~bivasm/notes/scribe/11CS30026.pdf>
- <https://mohitkarekar.com/posts/2023/compiler-frontend/> -- Compiler in Rust using pest.rs
- <https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/>

## Practical Files

- [Index Format.pdf](./Index%20Format.pdf)
- [Reference A - 01-07](./Reference%20Doc%20-%201.pdf)
- [Reference B - 08-11](./Reference%20Doc%20-%202.pdf)
