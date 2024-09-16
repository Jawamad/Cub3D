#include "../../inc/cub3d.h"


int	set_minimap(t_data *data)
{
	t_pos	map_pen;
	t_pos	map_reader;
	int		tile_size;

	tile_size = TILE;
	map_pen.x = tile_size * 2;
	map_pen.y = tile_size * 2;
	map_reader.x = search_player(data).x - 5;
	map_reader.y = search_player(data).y - 5;
	while (map_reader.y < search_player(data).y + 5 && map_reader.y < data->map_data.height)
	{
		while (map_reader.x < data->map_data.width && map_reader.x < search_player(data).x + 5)
		{
			if (map_reader.x >= 0 && map_reader.y >= 0)
				put_tile_mmap(map_pen, map_reader, data);
			map_pen.x += tile_size;
			map_reader.x++;
		}
		map_pen.x = tile_size * 2;
		map_reader.x = search_player(data).x - 5;
		map_pen.y += tile_size;
		map_reader.y++;
	}
	return (1);
}

void	put_tile_mmap(t_pos map_pen, t_pos map_reader, t_data *data)
{
	if (!is_floor_mmap(data->map_data.map[(int)map_reader.y][(int)map_reader.x]))
		paint_tile_mmap(map_pen.x, map_pen.y, 0xFF0000, data);
	if (!is_wall_mmap(data->map_data.map[(int)map_reader.y][(int)map_reader.x]))
		paint_tile_mmap(map_pen.x, map_pen.y, 0x00FF00, data);
	if (is_player_mmap(data->map_data.map[(int)map_reader.y][(int)map_reader.x]))
	{
		paint_tile_mmap(map_pen.x, map_pen.y, 0xFF0000, data);
		//put_player_mmap(data);
	}
}

void	put_player_mmap(t_data *data)
{	
	t_player	player;
	t_pos		pencil;
	int			tile;

	tile = TILE;
	player = data->map_data.player;
	pencil.y = player.ppos.y;
	pencil.x = player.ppos.x - (tile / 2);
}

void	paint_pixel_line(t_data *data, int len, t_pos start)
{
	while(start.x < (start.x - len))
	{
		mlx_pixel_put(data->mlx, data->mlx_win, start.x, start.y, 0x00FF00);
	}
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
