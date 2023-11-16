#ifndef shell_h
#define shell_h
/*
*commento
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
*comment
*/
void display_prompt(void);
void rudy_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(const char *command);




#endif /* shell.h */
