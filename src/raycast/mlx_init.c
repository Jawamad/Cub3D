#include "../../inc/cub3d.h"

void init_win(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 640, 360, "Tutorial Window");
}

void  init_map(t_data *data)
{
	char	c;

	data->map_data.map = malloc(sizeof(char*) * 4);
	data->map_data.map[0] = malloc(sizeof(char) * 12);
	data->map_data.map[0] = "11111111111";
	data->map_data.map[1] = malloc(sizeof(char) * 12);
	data->map_data.map[1] = "100N0000001";
	data->map_data.map[2] = malloc(sizeof(char) * 12);
	data->map_data.map[2] = "11111111111";
	data->map_data.height = 3;
	data->map_data.width = 11;
	data->map_data.player.ppos = search_player(data);
	c = data->map_data.map[(int)data->map_data.player.ppos.y][(int)data->map_data.player.ppos.x];
	if (c == 'N')
		data->map_data.player.pdir.y = data->map_data.player.ppos.y - 0.5;
	else if (c == 'O')
		data->map_data.player.pdir.y = data->map_data.player.ppos.x - 0.5;
	else if (c == 'E')
		data->map_data.player.pdir.y = data->map_data.player.ppos.x + 0.5;
	else
		data->map_data.player.pdir.y = data->map_data.player.ppos.y + 0.5;
}
