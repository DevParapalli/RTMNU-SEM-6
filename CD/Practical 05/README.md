# Practical 05: Recursive Descent Parser

## Aim

Design recursive descent parser for grammar `E:+EE|-EE|a|b`

## References

- <https://www.cs.rochester.edu/u/nelson/courses/csc_173/grammars/parsing.html>

## Theory

A parser is an algorithm that determines whether a given input string is in a language and, as a side-effect, usually produces a parse tree for the input. There is a procedure for generating a parser from a given context-free grammar.

### Recursive-descent Parsing

Recursive-descent parsing is one of the simplest parsing techniques that is used in practice. Recursive-descent parsers are also called top-down parsers, since they construct the parse tree top down (rather than bottom up).

The basic idea of recursive-descent parsing is to associate each non-terminal with a procedure. The goal of each such procedure is to read a sequence of input characters that can be generated by the corresponding non-terminal, and return a pointer to the root of the parse tree for the non-terminal. The structure of the procedure is dictated by the productions for the corresponding non-terminal.

The procedure attempts to "match" the right hand side of some production for a non-terminal.

- To match a terminal symbol, the procedure compares the terminal symbol to the input; if they agree, then the procedure is successful, and it consumes the terminal symbol in the input (that is, moves the input cursor over one symbol).
- To match a non-terminal symbol, the procedure simply calls the corresponding procedure for that non-terminal symbol (which may be a recursive call, hence the name of the technique).

## Practical Files

- [5.c](./5.c)
- *[5.py](./5.py) _Used for exploratory research._
- @[output.png](./output.png)
- @[output.pdf](./output.pdf)
- @[code.pdf](./code.pdf)