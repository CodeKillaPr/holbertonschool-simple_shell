# simple_shell

## Introduction

`simple_shell` is a simple UNIX command line interpreter that mimics basic functionality of traditional shells like `sh` and `bash`. This project is part of a learning exercise to understand the workings of shells and UNIX processes. `simple_shell` reads commands from the standard input or from a script file and executes them.

## Installation

To install `simple_shell`, clone this repository to your local machine and compile the sources using GCC.

```bash
git clone git@github.com:unknowguy404/holbertonschool-simple_shell.git
```

```bash
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell

Usage
To start simple_shell in interactive mode, simply run the executable:

./simple_shell

In interactive mode, you will see a simple prompt (simple_shell ) waiting for your commands. Type commands as you would in any standard shell:

simple_shell $ /bin/ls

To run the shell in non-interactive mode, you can pipe commands into it from the command line:

echo "/bin/ls" | ./simple_shell

Features
Executes commands in the PATH or specified with an absolute path.
Handles the env built-in command to print the current environment.
Implements a custom exit to exit the shell.
Handles errors like non-existent commands.
Parses commands with arguments.
Contributions
Contributions are welcome! If you'd like to contribute, please fork the repository and use a feature branch. Pull requests are warmly welcome.

When contributing to this repository, please first discuss the change you wish to make via issue, email, or any other method with the owners of this repository before making a change.

Authors:
Nelson Betancourt Aponte <github.com/unknowguy404>
Ramon Antonio Vega <github.com/rvdmntry>
```
