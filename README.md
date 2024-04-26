# simple_shell

## Introduction

`simple_shell` is a simple UNIX command line interpreter that mimics basic functionality of traditional shells like `sh` and `bash`. This project is part of a learning exercise to understand the workings of shells and UNIX processes. `simple_shell` reads commands from the standard input or from a script file and executes them.

## Installation

To install `simple_shell`, clone this repository to your local machine and compile the sources using GCC.

```bash
git clone git@github.com:unknowguy404/holbertonschool-simple_shell.git
```

## Compilation

```bash
cd holbertonschool-simple_shell
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
```

## Example

```bash
holbertonschool-simple_shell git:(Nelson) ✗ ./simple_shell
simple_shell ls
AUTHORS built_ins.c pathfinder.c simple_shell.c
README.md man_1_simple_shell simple_shell simple_shell.h
simple_shell pwd
/Users/killa/holbertonschool-simple_shell
simple_shell ls -l
total 128
-rw-r--r--@ 1 killa staff 182 Apr 18 12:59 AUTHORS
-rw-r--r-- 1 killa staff 1783 Apr 26 00:32 README.md
-rwxr-xr-x 1 killa staff 597 Apr 26 00:32 built_ins.c
-rw-r--r-- 1 killa staff 1999 Apr 26 00:32 man_1_simple_shell
-rwxr-xr-x 1 killa staff 991 Apr 26 09:19 pathfinder.c
-rwxr-xr-x 1 killa staff 34848 Apr 26 10:27 simple_shell
-rwxr-xr-x 1 killa staff 2942 Apr 26 09:16 simple_shell.c
-rwxr-xr-x 1 killa staff 654 Apr 26 00:32 simple_shell.h
simple_shell exit
➜ holbertonschool-simple_shell git:(Nelson) ✗ echo "/bin/ls /var" | ./simple_shell
MobileSoftwareUpdate backups empty log netboot run vm
OOPJit containers folders logs networkd select yp
agentx db install ma protected sntpd
at dextcores jabberd mail root spool
audit dirs_cleaner lib msgs rpc tmp

```

```bash
When contributing to this repository, please first discuss the change you wish to make via issue, email, or any other method with the owners of this repository before making a change.

Authors:
Nelson Betancourt Aponte <github.com/unknowguy404>
Ramon Antonio Vega <github.com/rvdmntry>
```
