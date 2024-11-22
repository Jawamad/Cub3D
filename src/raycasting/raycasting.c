#include "cub3d.h"

void	get_shorter_distance(t_data *data)
{
	
}

void	raycasting(t_data *data)
{
	int ray;

	ray = 0;
	data->ray.r_angle = data->player.p_angle - (data->player.fov_rad / 2);
	data->img_screen.img = mlx_new_image(data->mlx, SCR_WIDTH, SCR_HEIGHT);
	data->img_screen.addr = mlx_get_data_addr(data->img_screen.img, &data->img_screen.bits_per_pixel, &data->img_screen.line_length, &data->img_screen.endian);
	while (ray < SCR_WIDTH)
	{
		get_shorter_distance(data);//afaire
		display_wall(data, ray);//afaire
		ray++;
		data->ray.r_angle += data->player.fov_rad / SCR_WIDTH;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_screen.img, 0, 0);
}