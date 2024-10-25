#include "../../inc/cub3d.h"
void init_win(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 640, 360, "Tutorial Window");
}

void  init_map(t_data *data)
{
	char	c;
	data->map_data.player.angle = M_PI;

	data->map_data.map = malloc(sizeof(char*) * 10);
	data->map_data.map[0] = malloc(sizeof(char) * 12);
	data->map_data.map[0] = "11111111111";
	data->map_data.map[1] = malloc(sizeof(char) * 12);
	data->map_data.map[1] = "10000000001";
	data->map_data.map[2] = malloc(sizeof(char) * 12);
	data->map_data.map[2] = "10000000001";
	data->map_data.map[3] = malloc(sizeof(char) * 12);
	data->map_data.map[3] = "10000000001";
	data->map_data.map[4] = malloc(sizeof(char) * 12);
	data->map_data.map[4] = "10000000001";
	data->map_data.map[5] = malloc(sizeof(char) * 12);
	data->map_data.map[5] = "10000000001";
	data->map_data.map[6] = malloc(sizeof(char) * 12);
	data->map_data.map[6] = "10000000001";
	data->map_data.map[7] = malloc(sizeof(char) * 12);
	data->map_data.map[7] = "10000000001";
	data->map_data.map[8] = malloc(sizeof(char) * 12);
	data->map_data.map[8] = "10000000N01";
	data->map_data.map[9] = malloc(sizeof(char) * 12);
	data->map_data.map[9] = "11111111111";
	data->map_data.height = 10;
	data->map_data.width = 11;
	data->map_data.player.ppos = search_player(data);
	c = data->map_data.map[(int)data->map_data.player.ppos.y][(int)data->map_data.player.ppos.x];
	if (c == 'N')
		data->map_data.player.angle /= 2;
	else if (c == 'S')
		data->map_data.player.angle = 3 * data->map_data.player.angle /2;
	else if (c == 'E')
		data->map_data.player.angle = 0;
}
