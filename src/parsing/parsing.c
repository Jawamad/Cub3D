#include "../../inc/cub3d.h"

int	check_exten(char *av)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".cub";
	i = ft_strlen(av) - 1;
	j = 3;
	while (av[i] != '.')
	{
		if (av[i] != ext[j])
			ft_error(1);
		i--;
		j--;
	}
	return (0);
}

void	init_map_data(t_data *data)
{
	data->map_data.nb_column = 0;
	data->map_data.nb_row = 0;
	data->map_data.p_count = 0;
	data->map_data.width = 0;
	data->map_data.height = 0;
	data->map_data.NO = NULL;
	data->map_data.SO = NULL;
	data->map_data.WE = NULL;
	data->map_data.EA = NULL;
	data->map_data.CC = NULL;
	data->map_data.CF = NULL;
	data->map_data.count_line = 0;
}

void	line_north(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	i += 2;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	j = i;
	while (line[i] != ' ' && (line[i] <= 9 && line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	data->map_data.NO = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}

void	line_south(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	i += 2;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	j = i;
	while (line[i] != ' ' && (line[i] <= 9 && line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	data->map_data.SO = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}
void	line_west(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	i += 2;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	j = i;
	while (line[i] != ' ' && (line[i] <= 9 && line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	data->map_data.WE = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}

void	line_east(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	i += 2;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	j = i;
	while (line[i] != ' ' && (line[i] <= 9 && line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	data->map_data.EA = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}

void	line_ceilling(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	i += 1;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	j = i;
	while (line[i] != ' ' && (line[i] <= 9 && line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	data->map_data.EA = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}

void	line_floor(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	i += 1;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	j = i;
	while (line[i] != ' ' && (line[i] <= 9 && line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	data->map_data.EA = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}

void	check_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		line_north(line, data);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		line_south(line, data);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		line_west(line, data);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		line_east(line, data);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		line_ceilling(line, data);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		line_floor(line, data);
	else
		ft_error_data(data, 0);
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
	
}

void	read_option(char **av, t_data *data)
{
	int		file;
	char	*line;
	char	*map_line;

	file = open(av[1], O_RDONLY);
	if (!file)
		ft_error(2);
	line = get_next_line(file);
	if (!line)
		ft_error(3);
	check_line(line, data);
	map_line = ft_strdup("");
	while (1)
	{
		free(line);
		line = get_next_line(file);
		if (!line)
			break;
		check_line(line, data);
		if (data->map_data.count_line == 6)
			read_map(file, data);
	}
}

int	parsing(char **av, t_data *data)
{
	init_map_data(data);
	read_option(av, data);




	//data->map_data.map = read_map(av);
	//is_map_rectangle(data);
	//check_walls_and_char(data);
	//is_path_valid(av, data);
}