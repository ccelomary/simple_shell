#include <stdio.h>
#include <sys/types.h>

size_t _strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int check_diameter(char *str, char *diameter)
{
	size_t iter;

	iter = 0;
	while (str[iter] && diameter[iter] && str[iter] == diameter[iter])
		iter++;
	if (diameter[iter])
		return (0);
	if (str[iter] == diameter[iter - 1])
		return (2);
	return (1);
}

size_t backet_count(char *line, char *diameter)
{
	size_t counter, index, before, is_diameter;

	counter = 0;
	index = 0;
	before = 0;
	while (line[index])
	{
		is_diameter = check_diameter(line + index, diameter);
		if (is_diameter)
		{
			if (is_diameter == 2)
			{
				index++;
				before = 1;
			}
			else if (is_diameter == 1 && before)
			{
				before = 0;
				index++;
			}
			else
			{
				counter++;
				index += _strlen(diameter);
			}
		}
		else
			index++;
	}
	return (counter + 1);
}

int main(void)
{
	// printf("%d\n", is_diameter("||", "|"));
	// printf("%d\n", is_diameter("|", "||"));
	// printf("%d\n", is_diameter("|||", "||"));
	// printf("%d\n", is_diameter("|", "|"));
	printf("%lu\n", backet_count("hello||world|||again||World", "||"));
	return (0);
}
