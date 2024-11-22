#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	parsing(av, &data);


	printf("NO : %s\n", data.no);
	printf("SO : %s\n", data.so);
	printf("WE : %s\n", data.we);
	printf("EA : %s\n", data.ea);
	printf("C : %s\n", data.cc);
	printf("F : %s\n", data.cf);
	while (i < 14)
	{
		printf("ligne %d : %s\n", i, data.map[i]);
		i++;
	}


	if (data.map[0] != NULL)
		free_array(data.map);
	free_char_option(&data);

	
	return (0);
	//display_map(&data);
	//mlx_key_hook(data.mlx_win, handle_events, &data);
	//mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	//mlx_loop(data.mlx);
}