#include "shell.h"
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z') )
		return (1);
	else
		return (0);
}
int _atoi(char *s)
{
	int i=0, sign = 1, flag = 0, output;
	unsigned int result = 0;
while (s[i] != '\0' && flag != 2)
{
	if (s[i] == '-')
		sign *= -1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		flag = 1;
		result *= 10;
		result += (s[i] - '0');
	}
	else if (flag == 1)
		flag = 2;
	i++;
}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
