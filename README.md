# Xenon Compiler

A minimalist C-like compiler implementation built from scratch to explore compiler design fundamentals.

## About

Xenon is a toy programming language compiler built from scratch to understand compiler design fundamentals. This project implements a lexical analyzer, recursive descent parser, Abstract Syntax Tree (AST) construction, and interpreter for arithmetic expressions.

**Current Status**: Early development - supports basic arithmetic expression parsing and evaluation.

## Features

### Currently Implemented
- **Lexical Analysis**: Tokenizes input source code into meaningful symbols
- **Expression Parsing**: Recursive descent parser with operator precedence
- **AST Construction**: Builds abstract syntax trees for mathematical expressions  
- **AST Interpreter**: Tree-walking interpreter that evaluates expressions
- **Error Handling**: Basic syntax error reporting with line numbers

### In Development
- Assembly code generation
- Register management
- Variable declarations and assignments
- Control flow statements (if/else, loops)
- Function definitions and calls

## Prerequisites
- GCC/G++ compiler
- Make build system
- Linux/Unix environment (or WSL on Windows)

## Building

```bash
# Clone the repository
git clone https://github.com/RohanLambture/xenon.git
cd xenon

# Build the compiler
make

# Clean build artifacts
make clean
```

### Usage

```bash
# Run the compiler on an input file
./parser input output

# Example: Parse arithmetic expression
echo "12 + 3 * 5 - 8 / 3" > test.txt
./parser test.txt result.txt
```
