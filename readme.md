# Lexical Analyzer
A command-line C lexical analyzer that tokenizes source code and detects syntax errors.

## Description
This lexical analyzer parses C source files and identifies keywords, identifiers, operators, literals, and symbols. It validates numeric formats (decimal, hexadecimal, octal, binary), detects mismatched brackets and quotes, and reports syntax errors with line numbers.

## Features
- Tokenizes C source code into categories (keywords, identifiers, literals, operators, symbols)
- Supports multiple numeric formats (hex, octal, binary, float)
- Validates bracket matching: `()`, `{}`, `[]`
- Detects unclosed strings and character literals
- Handles single-line and multi-line comments
- Reports errors with line numbers
- Ignores preprocessor directives

## Installation
Clone the repository:
```bash
git clone https://github.com/ArjunVasavan/Lexical-analyzer.git
cd Lexical-analyzer
```

## Compilation
```bash
gcc *.c -o lexer
```

## Usage
### Analyze a C file
```bash
./lexer test.c
```

### Output Categories
- **Keywords**: C reserved words (int, float, if, while, etc.)
- **Identifiers**: Variable and function names
- **Numeric Literals**: Integers, floats, hex (0x), octal (0), binary (0b)
- **String Literals**: Text in double quotes
- **Character Literals**: Characters in single quotes
- **Operators**: Arithmetic, logical, bitwise operators
- **Symbols**: Special characters (semicolons, commas, etc.)

### Error Detection
- Invalid numeric formats
- Unclosed strings or character literals
- Mismatched brackets/parentheses
- Identifiers starting with digits
- Brackets/quotes not on the same line

## How It Works
The analyzer reads the input file character by character, building tokens based on patterns. It tracks bracket counts and line numbers to detect mismatches, validates numeric literals against their format rules, and reports errors immediately when found.

## Example
Input (`test.c`):
```c
int main() {
    int x = 0x1A;
    printf("Hello");
    return 0;
}
```

Output:
```
Keyword : int
Identifier : main
Symbols : (
Symbols : )
Symbols : {
...
```

## Author
Arjun Vasavan

## License
This project is licensed under the [MIT License](./LICENSE).

> © 2025 Arjun Vasavan
