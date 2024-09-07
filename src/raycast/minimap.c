#include "../inc/cub3d.h";

void	set_minimap(t_data *data)
{
	t_coord	*map_reader;

	map_reader = init_pos(0);
	while ((map_reader.x <= data->map_data.width) && map_reader.y <= (data->map_data.height))
	{
		// utiliser un buffer au lieu de put_pixel
		if (data->map_data.map[map_reader.y][map_reader.x])
		if 
		mlx_pixel_put(data->mlx, data->mlx_win, pencil.x++, pencil.y, "#0000FF");
		if (pencil.x == (data->map_data.height + 10) * 4 && pencil.y < (data->map_data.width + 10) *4)
		{
			pencil.x = 9;
			pencil.y++;
		}
	}
	//put_wall_mmap(data);
}

void	put_wall_mmap(t_data *data)
{
	t_pos pencil;

	pencil.x = 9;
	pencil.y = 9;
}

void	put_floor_mmap(t_data *data)
{

}

void	put_player_mmap(t_data *data)
{

}

t_coord	*search_player(t_data *data)
{
	t_coord *pos;
	pos = init_pos(0);
	while (data->map_data.map[pos->y][pos->x])
	{
		if (data->map_data.map[pos->y][pos->x] == 'P')
			return (pos);
		pos->x++;
		if (pos->x >= data->map_data.width)
		{
			pos->x = 0;
			pos->y++;
		}
	}
}