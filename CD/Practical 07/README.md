# Practical 07: Postfix Calculator

## Aim

Design a program to evaluate a postfix expression.

## Theory

Postfix notation, also known as reverse Polish notation (RPN), is a way of writing mathematical expressions in which the operator symbols follow their operands. It was named after the Polish mathematician Jan Łukasiewicz who introduced it in 1924.

In postfix notation, the expression "3 + 4 \* 5" would be written as "3 4 5 \* +", where the multiplication operator "*" follows its operands "4" and "5", and the addition operator "+" follows its operands "3" and the result of "4 \* 5".

Postfix notation has several advantages over infix notation (the more common way of writing mathematical expressions):

1. Unambiguity: Postfix notation is unambiguous, meaning that there is only one way to interpret a given expression. This is in contrast to infix notation, where the order of operations must be explicitly specified using parentheses.
2. Ease of parsing: Postfix notation is easy to parse because there is no need to worry about operator precedence or associativity. Operators are always applied to the two most recent operands.
3. Stack-based evaluation: Postfix notation can be evaluated using a simple stack data structure. When an operand is encountered, it is pushed onto the stack. When an operator is encountered, it pops the two most recent operands from the stack, applies the operator to them, and pushes the result back onto the stack.

For these reasons, postfix notation is commonly used in calculators, mathematical software, and other applications where expressions need to be parsed and evaluated quickly and accurately.

```sh
flex pfcalc.l && bison -d pfcalc.y && gcc lex.yy.c pfcalc.tab.c -o pfcalc.exe && ./pfcalc.exe
```

## Files

* [pfcalc.l](./pfcalc.l)
* [pfcalc.y](./pfcalc.y)