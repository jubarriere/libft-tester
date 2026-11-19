*This project has been created as part of the 42 curriculum by julbarri.*

# 42-Libft Tester #

## Description

Libft Tester is a tester for the 42 Libft project. It checks the 43 functions of the library (libc functions, additionals functions and linked lists) and detects memory leaks with Valgrind.

### Features

For each function, the tester :
- compare the result with the libc equivalent (if it exists);
- checks edge cases;
- frees every allocated result, so that Valgrind only reports leaks coming from the library;
- detects invalid reads and writes, even in functions that do not allocate memory.

### Structure

```
libft-tester/
|__ Makefile
|__ main.c
|__ tests/
|   |__ ft_isalpha_test.c
|   |__ ft_isdigit_test.c
|   |__ ...
|__ README.md
```

## Instructions

### Requirements
- Linux;
- `cc`, `make` and Valgrind.

### Installation

Git clone the tester **inside** the `libft` folder :
```bash
cd libft
git clone https://github.com/jubarriere/libft-tester.git
cd libft-tester
```
The tester expects `libft.a` and `libft.h` in the parent folder. If `libft.a` does not exist yet, it is built automatically with the library's Makefile.

### Compilation

```bash
make        #build the tester and run the tests under valgrind
make fast   #build the tester and run the tests without valgrind
make clean  #remove the tester
make re     #rebuild the tester and run the tests under valgrind
```
The tester is compiled with `-Wall -Wextra -Werror -g`, the header is searched in the parent folder, and the program is linked with the libft archive from the parent folder.

### Execution

`make` builds and runs the tests automatically.
Once built, the tester can also be run directly without Valgrind (same as `make fast`) :
```bash
./tester
```

Example output :
```bash
$   make
ft_isalpha : OK
ft_isdigit : OK
...
```
Each function prints `OK` if it passed all the tests, `KO` if not.

`make` runs valgrind in quiet mode (-q), it only prints memory errors and leaks. If nothing but the test result is displayed, the functions have no leaks or invalid memory access.


## Resources
- The 42 Libft subject for the expected behavior of each function;
- All the `man` pages (`man strcpy`, `man memmove`, etc.).

### AI usage
AI was used to explain some concepts (Valgrind, Makefile), and to write this README. The tests code was written and understood by me.