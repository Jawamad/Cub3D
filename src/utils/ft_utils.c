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

int	rgb_to_hex(char *rgb_str)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;
	int		color;

	rgb = ft_split(rgb_str, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	color = (r << 16) | (g << 8) | b;
	return (color);
}
