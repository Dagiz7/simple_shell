#include "shell.h"
char *_strncpy(char *dest, char *src, int n)
{char *s = dest;
	int i=0, j;
	while (i < n - 1 && src[i] != '\0'  )
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

char *_strncat(char *dest, char *src, int n)
{
	int i=0, j=0;
	char *s = dest;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
