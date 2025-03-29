# Pico Shell

A minimal shell implementation in C for Linux that supports built-in commands (`pwd`, `cd`, `echo`) and execution of external programs.

## Features
- **Built-in Commands:**
  - `pwd` - Prints the current working directory.
  - `cd <directory>` - Changes the working directory.
  - `echo <text>` - Prints text to the console.
- **Execution of External Commands:**
  - Runs programs like `ls`, `cat`, etc.
- **Error Handling:**
  - Displays an error message if an invalid command is entered.


## Usage
Run the shell:
```sh
./pico
```
Example commands:
```sh
PICO_SHELL> pwd
/home/nabil/Desktop/Pico

PICO_SHELL> cd /usr
current directory: /usr
PICO_SHELL> pwd
/usr

PICO_SHELL> echo Hello, world!
Hello, world!

PICO_SHELL> ls
bin  games  include  lib    lib64   libexec  local  sbin  share  src

PICO_SHELL> invalid_command
invalid Command
```

