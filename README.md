# Boolean Logic Interpreter

## Table of Contents

* [Description](#Description)
* [Environment](#Environment)
* [File Structure](#file-structure)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Author](#staff)

## Description
Boolean Logic Interpreter is a simple computer environment that can evaluate simple boolean expressions. The boolean operators that are supported within this version of the interpreter are: `parentheses`, `not`, `==`, `and`, `or`, `=`.
<br>
The operator precedence is shown in the table below:

| Precedence | Operator | Description | Associativity |
| ---------- | -------- | ----------- | ------------- |
| 1 | () | Parentheses | left-to-right |
| 2 | not | Logical NOT | right-to-left |
| 3 | == | Equality | left-to-right |
| 4 | and | Logical AND | left-to-right |
| 5 | or | Logical OR | left-to-right |
| 6 | = | Simple assignment | right-to-left |

<p> The lower the number in the precedence column the higher the value is implied.
</p>
Supported syntax: **T** to represent true and **F** to represent false.
To create a variable, the recognized keywords are uppercase letters in the english alphabet, i.e, A to Z excluding T and F as these are reserved keywords.

## Environment
<!-- macOS -->
<a href="https://www.apple.com/" target="_blank"></a>
OS: macOS Ventura (13.1)
<!-- c -->
<a href="https://www.cprogramming.com/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=C%20Language&color=5C6BC0&logo=c&logoColor=A8B9CC&labelColor=2F333A" alt="C Low level programming language"></a>
Language: C (c11)
Compiler: Clang 14.0.0
<!-- git -->
<a href="https://git-scm.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Git&color=F05032&logo=Git&logoColor=F05032&labelColor=2F333A" alt="git distributed version control system"></a>
Control version: Git
<!-- github -->
<a href="https://github.com" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github"></a>

Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## File Structure
* **Header files**
    * [main.h](main.h) - Main header file holding major function prototypes.
    * [_stack_.h](_stack_.h) - header file for stack data structure.
    * [_hash_.h](_hash_.h) - header file for hashtable data structure.
* [main.c](main.c) - Main function.
* [read_line.c](read_line.c) - Get input from the stdin.
* [split_line.c](split_line.c) - Tokenize the input obtained.
* [sh_loop.c](sh_loop) - Initiate REPL.
* [infix_postfix.c](infix_postfix.c) - Convert an infix expression to a postfix expression.
* [eval_postfix.c](eval_postfix.c) - Evaluate a postfix expression.
* [hsh](hsh) - Executable to run the interpreter.

## Installation
- Clone this repository: `git clone https://github.com/hanichris/boolean_logic-interpreter.git`
- Change directory into the repository: `cd boolean_logic-interpreter`
- Compile: `clang -std=c11 -Wall -Werror -Wextra -pedantic -fcolor-diagnostics -fansi-escape-codes -g *.c -o hsh`
- Run the interpreter in interactive mode: `./hsh`
- or run it in a non-interactive mode: example `echo "T and F" | ./hsh`

## Usage
While using the interpreter, ensure each entry is separated by whitespace including the parentheses and operators as is evident in the usecase below.
### Example of Use
First compile and run the executable file on your terminal. For compilation see [Installation](#installation)
```bash
$./hsh
ʕ•́ᴥ•̀ʔっ T and F
Answer: false

ʕ•́ᴥ•̀ʔっ T or F
Answer: true

ʕ•́ᴥ•̀ʔっ ( T and F ) == F
Answer: true
```
Create variables, use the approach below.
```bash
ʕ•́ᴥ•̀ʔっ X = F
Answer: false

ʕ•́ᴥ•̀ʔっ Y = not X
Answer: true

ʕ•́ᴥ•̀ʔっ not X and Y
Answer: true
```

## Bugs
No known bugs at the moment.

## Author
hanichris
