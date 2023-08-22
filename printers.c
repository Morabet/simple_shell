#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @OUT: either STDOUT or STDERR
 * Return: On success 1, else -1.
 */
int _putchar(char c, int OUT)
{
	return (write(OUT, &c, 1));
}

/**
 * _puts - function that prints a stringto stdout.
 * @str: pointer to string
 *
 * Return: void.
 */
void _puts(char *str)
{
	write(1, str, _strlen(str));
}

/**
 * _puts_err - function that prints a stringing to stderr.
 * @str: pointer to string
 *
 * Return: void.
 */
void _puts_err(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}
/**
 * print_number -  print a number.
 * @n: number.
 * @OUT: either stdout or stderr
 * Return: void.
 */
void print_number(int n, int OUT)
{
	unsigned int k = n;

	if (n < 0)
	{
		_putchar('-', OUT);
		n *= -1;
		k = n;
	}

	if (k / 10 != 0)
	{
		print_number(k / 10, OUT);
	}
	_putchar((k % 10) + '0', OUT);
}
/**
 * print_err - print the error message
 * @arg: the cmd input.
 * @i: the number of iteration
 * Return: void.
 */
void print_err(char *arg, int i)
{
	_puts_err("./hsh");
	_puts_err(": ");
	print_number(i, STDERR_FILENO);
	_puts_err(": ");
	_puts_err(arg);
	_puts_err(": not found\n");

}
