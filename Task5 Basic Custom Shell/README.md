# Basic Custom Shell – System Calls

## Overview

A simple Linux-like command shell developed using **C and POSIX APIs**. It allows users to execute basic terminal commands through a custom shell.

## Tech Stack

* C
* POSIX API
* `unistd.h`
* `sys/wait.h`

## Key Features

* Uses `fork()` to create child processes.
* Uses `execvp()` to execute commands.
* Uses `wait()` for process synchronization.
* Supports basic Linux terminal commands.

## How to Run

Compile:

```bash id="5qz8re"
gcc custom_shell.c -o custom_shell
```

Run:

```bash id="6y4dnc"
./custom_shell
```

## Learning Outcome

This project helped me understand **Linux system calls, process creation, child processes, and command execution
