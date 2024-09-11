#include "../../inc/cub3d.h"

int	set_minimap(t_data *data)
{
	t_coord	player;
	t_coord	pencil;

	player = search_player(data);
	printf("%d and %d\n", player.x, player.y);
	pencil.x = player.x - 5;
	pencil.y = player.y - 5;
	if (pencil.x < 0)
		pencil.x = 0;
	if (pencil.y < 0)
		pencil.y = 0;
	while (pencil.y < (player.y + 5) && pencil.y < data->map_data.height)
	{
		printf("%d < %d \n", pencil.y, (player.y + 5));
		while (pencil.x < (player.x + 5) && pencil.x < data->map_data.width)
		{
			put_tile_mmap(pencil.x, pencil.y, data);
			pencil.x++;
		}
		pencil.x = player.x - 5;
		pencil.y++;
	}
	return (0);
}

void	put_tile_mmap(int x, int y, t_data *data)
{
	if (!is_player_mmap(data->map_data.map[y][x]))
		paint_tile_mmap(x, y, 0x0000FF, data);
	if (!is_wall_mmap(data->map_data.map[y][x]))
		paint_tile_mmap(x, y, 0x00FF00, data);
	if (!is_floor_mmap(data->map_data.map[y][x]))
		paint_tile_mmap(x, y, 0xFF0000, data);
}

void	paint_tile_mmap(int x, int y, int color,t_data *data)
{
	t_coord pencil;

	pencil.x = x * 4;
	pencil.y = y * 4;
	while (pencil.y < y * 4 + 4)
	{
		while (pencil.x < x * 4 + 4)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, pencil.x, pencil.y, color);
			pencil.x++;
		}
		pencil.y++;
	}
}
int	is_wall_mmap(char c)
{
	if (c == '1')
		return (0);
	return(1);
}
int	is_player_mmap(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return(1);
}

int	is_floor_mmap(char c)
{
	if (c == '0')
		return (0);
	return(1);
}


t_coord	search_player(t_data *data)
{
	t_coord coord;

	coord = init_coord();
	while (data->map_data.map[coord.y][coord.x])
	{
		if (!is_player_mmap(data->map_data.map[coord.y][coord.x]))
			return (coord);
		coord.x++;
		if (coord.x >= data->map_data.width)
		{
			coord.x = 0;
			coord.y++;
		}
	}
	return(coord);
}