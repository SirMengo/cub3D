*This project has been created as part of the 42 curriculum by msimoes*

## Description
Get_Next_Line is a function that reads a file descriptor line by line, returning one line at a time on each successive call. It handles any file descriptor, including standard input, and correctly manages memory across calls using a static buffer.

The goal of this project is to learn about static variables, file descriptor reading, dynamic memory allocation, and buffer management in C. The function reads efficiently regardless of the buffer size defined at compile time.

## Instructions

### Compilation
Get_Next_Line is a library function and does not produce a standalone executable. To use it in a project, compile the source files together with your own code:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_file.c
```

You can define a custom buffer size at compile time using the `-D BUFFER_SIZE` flag. If not specified, the default buffer size is `50`.

### Usage
Include the header in your project:
```c
#include "get_next_line.h"
```

Then call the function in a loop to read all lines from a file descriptor:
```c
char *line;
int  fd;

fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Return Value
- Returns the next line read from the file descriptor, including the newline character `\n` if present
- Returns `NULL` when there is nothing left to read or if an error occurs

### Files
- `get_next_line.c`: Main function implementation
- `get_next_line_utils.c`: Helper functions used by `get_next_line`
- `get_next_line.h`: Header file with prototypes and the `BUFFER_SIZE` definition

### Examples
Read from a file:
```bash
cc -D BUFFER_SIZE=20 get_next_line.c get_next_line_utils.c main.c && ./a.out
```
Read from standard input:
```c
line = get_next_line(STDIN_FILENO);
```

## Resources
- [Read syscall - man7.org](https://www.man7.org/linux/man-pages/man2/read.2.html)
- [Static variables in C - GeeksForGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File descriptors - Wikipedia](https://en.wikipedia.org/wiki/File_descriptor)

### AI usage
No AI was used to write the code of this project. AI was only used to find problems with the code and suggest fixes.
It was also used to make a draft for the README.
