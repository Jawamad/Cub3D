#include "../../inc/cub3d.h"

void	init_map_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCR_WIDTH, SCR_HEIGHT,
			"WELCOME TO THE AWKWARD / CREEPY MUSEUM");
	if (!data->win)
	{
		free(data->mlx);
		exit (1);
	}
	data->nb_column = 0;
	data->nb_row = 0;
	data->p_count = 0;
	data->width = 0;
	data->height = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->cc = NULL;
	data->cf = NULL;
	data->count_line = 0;
	data->valid_map = 1;
	data->map = NULL;
}

void	read_map(int file, t_data *data)
{
	char	*line;
	char	*map_line;

	line = get_next_line(file);
	if (!line)
		ft_error_data(data, 1);
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(file);
	}
	if (!line)
		return (free(line), close(file), ft_error_data(data, 1));
	map_line = ft_strdup("");
	while (1)
	{
		map_line = ft_strjoin_gnl(map_line, line);
		free(line);
		line = get_next_line(file);
		if (!line)
			break ;
	}
	free(line);
	data->map = ft_split(map_line, '\n');
	return (close(file), free(map_line));
}

void	read_option(char **av, t_data *data)
{
	int		file;
	char	*line;

	file = open(av[1], O_RDONLY);
	if (!file)
		ft_error(2);
	line = get_next_line(file);
	if (!line)
		ft_error(3);
	check_line(line, data);
	free(line);
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			return (close(file), free(line));
		check_line(line, data);
		if (data->count_line == 6)
		{
			free(line);
			read_map(file, data);
			break ;
		}
		free(line);
	}
}

int	parsing(char **av, t_data *data)
{
	init_map_data(data);
	read_option(av, data);
	if (data->count_line != 6)
		return (ft_error_data(data, 1), 1);
	clean_color_cc(data);
	clean_color_cf(data);
	check_color(data);
	check_value_color(data);
	check_char_map(data);
	check_wall(data);
	return (0);
}
