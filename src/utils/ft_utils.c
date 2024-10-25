#include "../../inc/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void ft_fswap(float *a, float *b)
{
	float c;

	c = *a;
	*a = *b;
	*b = c;
}

int abs_val(int n) 
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
