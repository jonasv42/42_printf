
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("printing a char %c\n", 'c');
	ft_printf("H%cllo %corld", 'e', 'W');

	return (0);
}
