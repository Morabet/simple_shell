#include "shell.h"

/**
 * is_interactive - check if we are in interactive mode
 *
 * Return: if Success 0, else 1.
 */
int is_interactive(void)
{
	struct stat st;

	if (fstat(STDIN_FILENO, &st) == -1)
		return (1);
	if ((st.st_mode & S_IFMT) != S_IFIFO)
		return (0);
	else
		return (1);
}

/**
 * multiple_cmd - check if there are multiple cmds.
 * @line: the cmd line.
 * Return: an array of strings of each cmd or NULL.
 */
char **multiple_cmd(char *line)
{
	char **arr;

	if (_strchr(line, ';') == -1)
		return (NULL);
	arr = string_to_words(line, ';');
	if (!arr)
		return (NULL);

	return (arr);
}
/**
 * input_loop - make a loop for the user input cmd
 * @env: passing environment variables.
 * @line: the input line.
 *
 * Return: on Success 0, else 1.
 */

int input_loop(char *line, char **env)
{
	char **args, **mult_cmd;
	int result = 0, read, i = 1, ex = 0, num_cmd = 0, j;

	while (1)
	{
		read = _getline(line, BUFFER);
		if (read == -1)
			break;	/** EOF or Ctrl-D **/
		line = strtok(line, "#\n");	/** remove \n OR stop at #**/
		j = 0;
		mult_cmd = multiple_cmd(line); /** check if there are multiple cmds**/
		num_cmd = mult_cmd ? array_size(mult_cmd) : 0;
loop:
		if (num_cmd > 0)
			args = string_to_words(mult_cmd[j++], ' ');
		else
			args = string_to_words(line, ' ');
		if (!args)
			continue;
		ex = _built_ins(args, env, i);
		if (ex != -1)
		{
			if (_strcmp(*args, "exit") == 0 && ex != 1 && ex != 2)
			{
				if (ex != 0)
					result = ex;
				free_array(args);
				break;
			}
			free_array(args);
			continue;
		}
		result = run_cmd(args, env, i++);
		free_array(args);
		if (--num_cmd > 0)
			goto loop;
		if (mult_cmd)
			free_array(mult_cmd);
	}
	return (result);
}
