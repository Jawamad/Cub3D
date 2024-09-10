#include "../../inc/cub3d.h"

void	set_minimap(t_data *data)
{
	t_coord	*player;
	t_coord	pencil;

	player = search_player(data);
	pencil.x = player->x - 5;
	pencil.y = player->y - 5;
	if (pencil.x < 0)
		pencil.x = 0;
	if (pencil.y < 0)
		pencil.y = 0;
	while (pencil.y < (player->y + 5) && pencil.y < data->map_data.height)
	{
		while (pencil.x < (player->x + 5) && pencil.x < data->map_data.width)
		{
			put_tile_mmap(pencil.x, pencil.y, data);
			pencil.x++;
		}
		pencil.y++;
	}
	free(player);//a verifier
}

void	put_tile_mmap(int x, int y, t_data *data)
{
	if (!is_player_mmap(data->map_data.map[y][x]))
		paint_tile_mmap(x, y, 0xFFFFFF, data);
	/* if (!is_wall_mmap(data->map_data.map[y][x]))
		paint_tile_mmap(x, y, 16777215, data); */
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

int	is_player_mmap(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return(1);
}


t_coord	*search_player(t_data *data)
{
	t_coord *pos;

	pos = init_pos(0);
	while (data->map_data.map[pos->y][pos->x])
	{
		if (!is_player_mmap(data->map_data.map[pos->y][pos->x]))
			return (pos);
		pos->x++;
		if (pos->x >= data->map_data.width)
		{
			pos->x = 0;
			pos->y++;
		}
	}
	return(NULL);
}