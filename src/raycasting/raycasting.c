#include "cub3d.h"

double	get_horizontal_distance(t_data *data)
{
	double	h_x;
	double	h_y;
	double	inter_x;
	double	inter_y;
}

double	get_vertical_distance(t_data *data)
{
	double	v_x;
	double	v_y;
	double	inter_x;
	double	inter_y;
}

void	get_shorter_distance(t_data *data)
{
	double	h_distance;
	double	v_distance;

	h_distance = get_horizontal_distance(data);
	v_distance = get_vertical_distance(data);
	if (h_distance <= v_distance)
	{
		data->ray.r_distance = h_distance;
		data->ray.flag = 1;
	}
	else
	{
		data->ray.r_distance = v_distance;
		data->ray.flag = 0;
	}
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