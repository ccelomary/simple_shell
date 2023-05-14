#include "../shell.h"
#include <stdio.h>

void free_int(void *data)
{
	free(data);
}

int main()
{
	list_t *my_list = NULL;

	int *num1 = (int *)malloc(sizeof(int));
	*num1 = 10;
	add_to_list(&my_list, num1);

	int *num2 = (int *)malloc(sizeof(int));
	*num2 = 20;
	add_to_list(&my_list, num2);

	int *num3 = (int *)malloc(sizeof(int));
	*num3 = 30;
	add_to_list(&my_list, num3);

	int *num4 = malloc(sizeof(int));
	*num4 = 40;
	add_to_list(&my_list, num4);
	printf("List elements:\n");
	while (my_list != NULL)
	{
		int *num = (int *)pop_from_list(&my_list);
		printf("%d\n", *num);
		free(num);
	}

	free_list(my_list, free_int);
	return 0;
}
