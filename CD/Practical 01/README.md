# Practical 01 - Recognition of (a|b)*abb

## Aim

Write a lex program to recognize valid strings using regular expression: `(a|b)*abb`

## Theory

Regex are used to define patterns for matching specific sequences of characters in the input code, forming the foundation of lexical analysis, the first phase of a compiler.

- **Key Concepts:**
  - **Character Classes:** `[a-zA-Z]`, `[0-9]`, `.` (any character), `\w` (word characters), `\s` (whitespace), `\d` (digits), etc.
  - **Quantifiers:** `*` (zero or more), `+` (one or more), `?` (zero or one), `{n}` (exactly n times), `{n,}` (at least n times)
  - **Anchors:** `^` (beginning of line), `$` (end of line)
  - **Alternation:** `|` (either or)
  - **Grouping:** `()` (for creating sub-patterns)

**2. Flex (Fast Lexical Analyzer Generator):**

Flex is a tool that generates a lexical analyzer (scanner) from a set of regular expression patterns and corresponding C code actions.

- **Syntax:**
  - **Rules:** Define regular expression patterns and actions:

    ```flex
    %%
    pattern  { action }
    %%
    ```

  - **Patterns:** Use standard regex syntax with some additions:
    - `.` (any character except newline), `\n` (newline)
    - `[]` (character classes), `[^]` (negated character classes)
    - `^` (beginning of text), `$` (end of text)
    - `\<` (beginning of word), `\>` (end of word)
    - `\|` (alternation), `()*+?` (repetition)
  - **Actions:** C code to execute when a pattern matches, often returning tokens.
- **Example:**

   ```flex
   %%
   [0-9]+  { return NUMBER; }
   [a-zA-Z]+ { return IDENTIFIER; }
   "+"|"-"|"*" { return yytext[0]; }  // Return single-character operators
   "(" { return LPAREN; }
   ")" { return RPAREN; }
   %%
   ```

## Practical Files List

- [1.l](./1.l)
