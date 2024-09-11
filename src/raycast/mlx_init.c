#include "../../inc/cub3d.h"

void init_win(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 640, 360, "Tutorial Window");
}

void  init_map(t_data *data)
{
    data->map_data.map = malloc(sizeof(char*) * 4);
    data->map_data.map[0] = malloc(sizeof(char) * 12);
    data->map_data.map[0] = "11111111111";
    data->map_data.map[1] = malloc(sizeof(char) * 12);
    data->map_data.map[1] = "10000000N01";
    data->map_data.map[2] = malloc(sizeof(char) * 12);
    data->map_data.map[2] = "11111111111";
    data->map_data.height = 3;
    data->map_data.width = 11;
}