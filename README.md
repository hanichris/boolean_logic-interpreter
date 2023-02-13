# Boolean Logic Interpreter

## Table of Contents

* [Description](#Description)
* [Environment](#Environment)
* [File Structure](#file-structure)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Staff](#staff)
* [License](#license)

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
    * main.h - Main header file holding major function prototypes.
    * _stack_.h - header file for stack data structure.
    * _hash_.h - header file for hashtable data structure.
* [main.c](main.c) - Main function.
* [read_line.c](read_line.c) - Get input from the stdin.
* [split_line.c](split_line.c) - Tokenize the input obtained.
* [sh_loop](sh_loop) - Initiate REPL.

## Installation
- Clone this repository: `git clone https://github.com/hanichris/boolean_logic-interpreter.git`
- Change directory into the repository: `cd boolean_logic-interpreter`
- Compile: `clang -std=c11 -Wall -Werror -Wextra -pedantic -fcolor-diagnostics -fansi-escape-codes -g *.c -o hsh`
- Run the interpreter in interactive mode: `./hsh`
- or run it in a non-interactive mode: example `echo "T and F" | ./hsh`

## Usage


## Example of Use

