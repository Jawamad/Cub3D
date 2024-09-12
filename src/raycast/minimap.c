#include "../../inc/cub3d.h"

int	set_minimap(t_data *data)
{
	t_pos	player;
	t_pos	pencil;

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
	{
		paint_tile_mmap(x, y, 0x0000FF, data);

	}
	if (!is_wall_mmap(data->map_data.map[y][x]))
		paint_tile_mmap(x, y, 0x00FF00, data);
	if (!is_floor_mmap(data->map_data.map[y][x]))
		paint_tile_mmap(x, y, 0xFF0000, data);
}

void	paint_tile_mmap(int x, int y, int color,t_data *data)
{
	t_coord	pencil;
	int		format;

	format = TILE;
	pencil.x = x * format;
	pencil.y = y * format;
	while (pencil.y < (y * format + format))
	{
		while (pencil.x < (x * format + format))
		{
			mlx_pixel_put(data->mlx, data->mlx_win, pencil.x, pencil.y, color);
			pencil.x++;
		}
		pencil.x = x * format;
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


t_pos	search_player(t_data *data)
{
	t_pos	pos;

	pos = init_pos();
	while (data->map_data.map[(int)pos.y][(int)pos.x])
	{
		if (!is_player_mmap(data->map_data.map[(int)pos.y][(int)pos.x]))
			return (pos);
		pos.x++;
		if (pos.x >= data->map_data.width)
		{
			pos.x = 0;
		pos.y++;
		}
	}
	return(pos);
}