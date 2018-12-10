#include <stdio.h>



void	ft_fct()
{
	static int i = 0;

	i++;
	printf ("%d\n", i);
}

int	main(void)
{
	back:
	ft_fct();
	getchar();
	goto back;
}

