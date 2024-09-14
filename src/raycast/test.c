#include "../../inc/cub3d.h"

void	mmapset(t_data *data)
{
	t_pos	map_pen;
	t_pos	map_reader;

	map_pen.x = 16;
	map_pen.y = 16;
	map_reader.x = search_player(data).x - 5;
	map_reader.y = search_player(data).y - 5;
	if (map_reader.x < 0)
		map_reader.x = 0;
	if (map_reader.y < 0)
		map_reader.y = 0;
	while (map_pen.y < 160)
	{
		while (((int)map_pen.x % 16) != 0)
		{
			if (((int)map_pen.x % 16) == 0)
			map_pen.x++;
		}
		map_pen.y++;
	}
}
