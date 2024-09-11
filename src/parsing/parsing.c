#include "../../inc/cub3d.h"

void	init_map_data(t_data *data)
{
	data->map_data.nb_column = 0;
	data->map_data.nb_row = 0;
	data->map_data.p_count = 0;
	data->map_data.width = 0;
	data->map_data.height = 0;
	data->map_data.no = NULL;
	data->map_data.so = NULL;
	data->map_data.we = NULL;
	data->map_data.ea = NULL;
	data->map_data.cc = NULL;
	data->map_data.cf = NULL;
	data->map_data.count_line = 0;
	data->map_data.valid_map = 1;
}

void	read_map(int file, t_data *data)
{
	char	*line;
	char	*map_line;

	line = get_next_line(file);
	if (!line)
		ft_error(3);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(file);
	}
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
	data->map_data.map = ft_split(map_line, '\n');
	close(file);
	free(map_line);
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
	while (1)
	{
		free(line);
		line = get_next_line(file);
		if (!line)
			break ;
		check_line(line, data);
		if (data->map_data.count_line == 6)
		{
			free(line);
			read_map(file, data);
			break ;
		}
	}
}

int	parsing(char **av, t_data *data)
{
	init_map_data(data);
	read_option(av, data);
	if (data->map_data.count_line != 6)
		return (ft_error_data(data, 1), 1);
	clean_color_cc(data);
	clean_color_cf(data);
	check_color(data);
	check_value_color(data);
	check_char_map(data);
	check_wall(data);
	return (0);
}
