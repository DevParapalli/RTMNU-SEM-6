# Compiler Design

## Tools Required

- Flex: <https://gnuwin32.sourceforge.net/packages/flex.htm>
- Bison: <https://gnuwin32.sourceforge.net/packages/bison.htm>

## Usage instructions

- only flex
  - `flex <filename>.l`
  - `gcc lex.yy.c -lfl`
  - `./a.exe`
- flex and bison
  - `flex <filename>.l`
  - `bison -d <filename>.y`
  - `gcc lex.yy.c <filename>.tab.c -lfl`
