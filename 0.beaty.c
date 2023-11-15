#include "shell.h"

/**
 * execute_command - Execute a shell command
 * @command: The command to be executed
 *
 * Description: This function takes a command as a parameter, forks a child
 * process, and executes the command using execvp. The parent process waits
 * for the child to complete.
 */
void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		rudy_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child process */

		/* Parse the command and its arguments */
		char *args[128]; /* Maximum 128 arguments (adjust as needed) */
		int arg_count = 0;

		char *token = strtok((char *)command, " ");
			while (token != NULL)

		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /* Null-terminate the arguments array */

		/* Execute the command */
		execvp(args[0], args);

		/* If execvp fails, print an error message */
		rudy_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

/**
 * main - Entry point for the shell
 *
 * Description: This is the main function for the simple shell. It displays a
 * prompt, reads a command from the user, and executes the command using the
 * execute_command function.
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		/* Display prompt and read command */
		display_prompt();
		command = read_command();

		/* Execute the command */
		execute_command(command);

		/* Free allocated memory */
		free(command);
	}

	return (0);
}
