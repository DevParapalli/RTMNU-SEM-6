# Practical 06: Bison Calculator

## Aim

Design a program for basic calculator using yacc or bison.

## Theory

Yacc (Yet Another Compiler Compiler) is a tool that helps in building compilers and interpreters. It takes a grammar specification for a language and generates a parser for that language. Bison is a popular, free, and compatible implementation of Yacc.

Yacc/Bison uses LALR(1) parsing algorithm, which stands for Look-Ahead Left-to-Right Rightmost Derivation (1 Token lookahead). It is a type of LR parser that uses only one token of look-ahead.

A yacc/bison specification file typically has two types of sections: declarations and rules.

Declarations:

* `%token`: defines a token type
* `%left`, `%right`, `%nonassoc`: define the precedence and associativity of operators

Rules:

* `%%`: marks the beginning of the rules section
* `rule : expression ;`: defines a rule, which consists of a list of tokens or non-terminals that form a valid construct in the language

```sh
flex ifcalc.l && bison -d ifcalc.y && gcc lex.yy.c ifcalc.tab.c -o ifcalc.exe && ./ifcalc.exe
```

## Files

* [ifcalc.l](./ifcalc.l)
* [ifcalc.y](./ifcalc.y)
* *[code_output.pdf](./code_output.pdf)
