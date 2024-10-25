#include "../../inc/cub3d.h"


int	set_minimap(t_data *data)
{
	t_pos	map_pen;
	t_pos	map_reader;
	int		tile_size;

	tile_size = TILE;
	map_pen.x = tile_size;
	map_pen.y = tile_size;
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
		map_pen.x = tile_size;
		map_reader.x = search_player(data).x - 5;
		map_pen.y += tile_size;
		map_reader.y++;
	}
	return (1);
}

void	put_tile_mmap(t_pos map_pen, t_pos map_reader, t_data *data)
{
	printf("x %f y %f\n", map_pen.x, map_pen.y);
	if (!is_floor_mmap(data->map_data.map[(int)map_reader.y][(int)map_reader.x]))
		paint_tile_mmap(map_pen.x, map_pen.y, 0xFF0000, data);
	if (!is_wall_mmap(data->map_data.map[(int)map_reader.y][(int)map_reader.x]))
		paint_tile_mmap(map_pen.x, map_pen.y, 0x00FF00, data);
	if (!is_player_mmap(data->map_data.map[(int)map_reader.y][(int)map_reader.x]))
	{
		paint_tile_mmap(map_pen.x, map_pen.y, 0xFF0000, data);
		//put_player_mmap(data);
	}
}

void	put_player_mmap(t_data *data)
{	
	t_arrow arrow;

	arrow = g_player_arrow(data->map_data.player);
	check_arrow_dir(data, &arrow);
	draw_filled_triangle(data, &arrow);
}

void	draw_filled_triangle(t_data *data, t_arrow *arrow)
{
	float inv_slope1;
	float inv_slope2;
	float curx1;
	float curx2;
	int y;

	inv_slope1 = (arrow->left.x - arrow->head.x) / (arrow->left.y - arrow->head.y);
	inv_slope2 = (arrow->right.x - arrow->head.x) / (arrow->right.y - arrow->head.y);
	curx1 = arrow->head.x;
	curx2 = arrow->head.x;
	y = arrow->head.y;
	while(y <= arrow->left.y)
	{
		mlx_line_put(data->mlx, data->mlx_win, curx1, y, curx2, y, 0x0000FF);
		curx1 += inv_slope1;
		curx2 += inv_slope2;
		y++;
	}
	inv_slope1 = (arrow->right.x - arrow->left.x) / (arrow->right.y -arrow->left.y);
	curx1 = arrow->left.x;
	y = arrow->left.y;
	while(y <= arrow->right.y)
	{
		mlx_line_put(data->mlx, data->mlx_win, curx1, y, curx2, y, 0x0000FF);
		curx1 += inv_slope1;
		curx2 += inv_slope2;
		y++;
	}
}


void check_arrow_dir(t_data *data, t_arrow *arrow)
{
	if (arrow->left.y < arrow->head.y)
	{
		ft_fswap(&arrow->head.x, &arrow->left.x);
		ft_fswap(&arrow->head.y, &arrow->left.y);
	}
	if (arrow->right.y < arrow->head.y)
	{
		ft_fswap(&arrow->head.x, &arrow->right.x);
		ft_fswap(&arrow->head.y, &arrow->right.y);
	}
	if (arrow->right.y < arrow->left.y)
	{
		ft_fswap(&arrow->left.x, &arrow->right.x);
		ft_fswap(&arrow->left.y, &arrow->right.y);
	}
}


t_arrow g_player_arrow(t_player player)
{
	float pi;
	int tile_size;
	t_arrow arrow;

	tile_size = TILE;
	pi = M_PI;
	arrow.head.x = player.ppos.x + cos(player.angle) * tile_size / 2;
	arrow.head.y = player.ppos.y + sin(player.angle) * tile_size / 2;
	arrow.left.x = player.ppos.x + cos(player.angle + pi / 2) * (tile_size / 2) * 0.9;
	arrow.left.y = player.ppos.y + sin(player.angle + pi / 2) * (tile_size / 2) * 0.9;
	arrow.right.x = player.ppos.x + cos(player.angle - pi / 2) * (tile_size / 2) * 0.9;
	arrow.right.y = player.ppos.y + sin(player.angle - pi / 2) * (tile_size / 2) * 0.9;
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
	pencil.x = x;
	pencil.y = y;
	while (pencil.y < (y + format))
	{
		while (pencil.x < (x + format))
		{
			mlx_pixel_put(data->mlx, data->mlx_win, pencil.x, pencil.y, color);
			pencil.x++;
		}
		pencil.x = x;
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
