#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	parsing(av, &data);
	//display_map(&data);
	//mlx_key_hook(data.mlx_win, handle_events, &data);
	//mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	//mlx_loop(data.mlx);
}