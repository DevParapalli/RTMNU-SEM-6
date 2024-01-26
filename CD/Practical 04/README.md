# Practical 04: Elimination of Left Recursion

## Aim

Write a C program to eliminate left recursion from grammar.

## Test Cases

1. `E: E+E | E.E | id`
2. `S: (L) | a` & `L: L,S | S`

## Theory

A grammer is said to have left recursion if it contains a production

$$ A \rightarrow  A\alpha | \beta $$

where $\alpha$ is a string of symbols

### Elimination of Left Recursion

If

$$A \rightarrow A\alpha_1 | A\alpha_2 |...| A\alpha_x | B_1 | B_2 | ... |B_y$$ 

is a grammer, where all $B_y$ are not starting from $A$

We obtain a non left-recursive grammer by

Collect all $B_y$, append with $A'$, then provide a new prodution

$$ A' \rightarrow \alpha_1A' | \alpha_2A'|...| \epsilon  $$

## References

- <https://www.csd.uwo.ca/~mmorenom/CS447/Lectures/Syntax.html/node8.html>
- <https://www.geeksforgeeks.org/removing-direct-and-indirect-left-recursion-in-a-grammar/amp/>