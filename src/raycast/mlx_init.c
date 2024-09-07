#include "../inc/cub3d.h";

void init_win(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 640, 360, "Tutorial Window");
    mlx_loop(data->mlx);
}