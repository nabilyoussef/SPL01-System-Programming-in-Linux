# MyFemtoShell

## Description
MyFemtoShell is a simple command-line shell program written in C. It provides basic command handling for:
- `echo <message>`: Prints the given message.
- `exit`: Terminates the shell.
- Invalid commands are notified with an error message.

## Features
- Reads user input from the command line.
- Recognizes `exit` and `echo` commands.
- Prints an error message for unrecognized commands.
- Runs in a loop until the `exit` command is entered.

## How It Works
1. The program continuously prompts the user with `MyFemtoShell:~$`.
2. It reads user input using `fgets()` and removes the trailing newline.
3. The first four characters of the input are extracted as the command.
4. If the command is:
   - `exit`: The loop terminates.
   - `echo`: Prints the rest of the user input after "echo".
   - Invalid: Displays an error message.



### Execution
```sh
./MyFemtoShell
```

### Example Usage
```
MyFemtoShell:~$ echo Hello, world!
Hello, world!
MyFemtoShell:~$ exit
Good Bye :)
```



