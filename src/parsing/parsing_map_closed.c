#include "../../inc/cub3d.h"

int	check_in_map(char **map_cpy, int x, int y, t_data *data)
{
	if (x == 0 || x == ft_strlen_gnl(map_cpy[y]) - 1
		|| y == 0 || y == data->nb_row - 1)
		return (1);
	if (x + 1 > ft_strlen_gnl(map_cpy[y - 1])
		|| x + 1 > ft_strlen_gnl(map_cpy[y + 1]))
		return (1);
	return (0);
}

/* void	check_angle(char **map_cpy, int y, int x, t_data *data)
{
	if (map_cpy[y - 1][x] == ' ' || map_cpy[y + 1][x] == ' '
	|| map_cpy[y][x - 1] == ' ' || map_cpy[y][x + 1] == ' '
	|| map_cpy[y - 1][x - 1] == ' ' || map_cpy[y - 1][x + 1] == ' '
	|| map_cpy[y + 1][x - 1] == ' ' || map_cpy[y + 1][x + 1] == ' ')
		data->map_data.valid_map = 0;
} */

void	check_angle(char **map_cpy, int y, int x, t_data *data)
{
	if (map_cpy[y - 1][x] == ' ' || map_cpy[y + 1][x] == ' '
	|| map_cpy[y][x - 1] == ' ' || map_cpy[y][x + 1] == ' ')
		data->valid_map = 0;
}

void	is_closed(char **map_cpy, int y, int x, t_data *data)
{
	if (map_cpy[y][x] != '0')
		return ;
	if (check_in_map(map_cpy, x, y, data) == 1)
	{
		data->valid_map = 0;
		return ;
	}
	map_cpy[y][x] = '1';
	check_angle(map_cpy, y, x, data);
	is_closed(map_cpy, y - 1, x, data);
	is_closed(map_cpy, y + 1, x, data);
	is_closed(map_cpy, y, x - 1, data);
	is_closed(map_cpy, y, x + 1, data);
}

void	check_wall(t_data *data)
{
	int		x;
	int		y;
	char	**map_cpy;

	y = -1;
	map_cpy = malloc(sizeof(char *) * (data->nb_row + 1));
	while (data->map[++y])
		map_cpy[y] = ft_strdup(data->map[y]);
	map_cpy[y] = NULL;
	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == '0')
				is_closed(map_cpy, y, x, data);
			if (data->valid_map == 0)
				return (free_array(map_cpy), ft_error_data(data, 5));
			x++;
		}
		y++;
	}
	free_array(map_cpy);
}
