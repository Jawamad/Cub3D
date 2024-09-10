#include "../../inc/cub3d.h"

void init_win(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 640, 360, "Tutorial Window");
    mlx_loop(data->mlx);
    data->map_data.map[0] = "11111111111";
    data->map_data.map[1] = "10000N00001";
    data->map_data.map[2] = "11111111111";

}