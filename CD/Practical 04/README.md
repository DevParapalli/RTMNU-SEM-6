# Practical 04: Elimination of Left Recursion

## Aim

Write a C program to eliminate left recursion from grammar.

## Test Cases

1. `E: E+E | E.E | id`
2. `S: (L) | a` & `L: L,S | S`

## Theory

A grammar is said to have left recursion if it contains a production

$$ A \rightarrow  A\alpha | \beta $$

where $\alpha$ is a string of symbols

### Elimination of Left Recursion

If

$$ A \rightarrow A\alpha_1 | A\alpha_2 |...| A\alpha_x | B_1 | B_2 | ... |B_y $$

is a grammar, where all $B_y$ are not starting from $A$

We obtain a non left-recursive grammar by

Collect all $B_y$, append with $A'$, then provide a new production

$$ A' \rightarrow \alpha_1A' | \alpha_2A'|...| \epsilon  $$

For elimination of indirect left recursion, convert to direct left recursion, and then eliminate.

- For each non terminal $A_i$:
  - Repeat until an iteration leaves the grammer unchanged:
    - For each production $A_i \rightarrow \alpha_i$, $\alpha_i$ being a sequence of terminals and non terminals:
      - If $\alpha_i$ begins with a non terminal $A_j$ and $j \lt i$:
        - Let $\beta_i$ be $\alpha_i$ with $A_j$ removed
        - Remove the production $A_i \rightarrow \alpha_i$
        - For each production $A_j \rightarrow \alpha_j$:
          - Add the rule $A_i \rightarrow \alpha_j\beta_i$
  - Remove direct left recursion for $A_i$ as described above.

## References

- <https://www.csd.uwo.ca/~mmorenom/CS447/Lectures/Syntax.html/node8.html>
- <https://www.geeksforgeeks.org/removing-direct-and-indirect-left-recursion-in-a-grammar/>
