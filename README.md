# ast_parser

Script for deleting prefix in .ast files

## Installation

```bash
git clone git@github.com:sixanimar/ast_parser.git
```

## Usage

Copy .ast file into /ast_parser

Create executable by running make command

```bash
jguscins@DESKTOP-M8IUFS4:~/ast_parser$ make
Compiling
gcc -Wall -Wextra src/parser.c src/strjoin.c src/strlen.c -o pars
Compilation done
```
To pars a file

```bash
jguscins@DESKTOP-M8IUFS4:~/ast_parser$ ./pars filename.astpars filename.ast
```
