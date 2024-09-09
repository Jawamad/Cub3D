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
	data->map_data.no = NULL;
	data->map_data.so = NULL;
	data->map_data.we = NULL;
	data->map_data.ea = NULL;
	data->map_data.cc = NULL;
	data->map_data.cf = NULL;
	data->map_data.count_line = 0;
	data->map_data.valid_map = 1;
}

void	line_cardinal(char *line, t_data *data, int flag)
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
	while (line[i] != ' ' && (line[i] <= 9 || line[i] >= 13))
		i++;
	if (line[j] != '.' && line[j + 1] != '/')
		ft_error_data(data, 0);
	if (flag == 1)
		data->map_data.no = ft_strndup_gnl(line + j, (i - j));
	if (flag == 2)
		data->map_data.so = ft_strndup_gnl(line + j, (i - j));
	if (flag == 3)
		data->map_data.we = ft_strndup_gnl(line + j, (i - j));
	if (flag == 4)
		data->map_data.ea = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}

void	line_color(char *line, t_data *data, int flag)
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
	while (line[i] != '\n')
		i++;
	if (flag == 1)
		data->map_data.cc = ft_strndup_gnl(line + j, (i - j));
	if (flag == 2)
		data->map_data.cf = ft_strndup_gnl(line + j, (i - j));
	data->map_data.count_line += 1;
}

void	check_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
		return ;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		line_cardinal(line, data, 1);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		line_cardinal(line, data, 2);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		line_cardinal(line, data, 3);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		line_cardinal(line, data, 4);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		line_color(line, data, 1);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		line_color(line, data, 2);
	else
		ft_error_data(data, 1);
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

void	check_color(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (data->map_data.cc[++i] != '\0')
	{
		if (data->map_data.cc[i] == ',')
			count += 1;
		if (!ft_isdigit(data->map_data.cc[i]) && data->map_data.cc[i] != ',')
			ft_error_data(data, 2);
	}
	if (count != 2)
		ft_error_data(data, 2);
	i = -1;
	count = 0;
	while (data->map_data.cf[++i] != '\0')
	{
		if (data->map_data.cf[i] == ',')
			count += 1;
		if (!ft_isdigit(data->map_data.cf[i]) && data->map_data.cf[i] != ',')
			ft_error_data(data, 2);
	}
	if (count != 2)
		ft_error_data(data, 2);
}

void	clean_color_cc(t_data *data)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;

	i = 0;
	while (data->map_data.cc[i])
	{
		if (data->map_data.cc[i] == ' ' || (data->map_data.cc[i] >= 9
				&& data->map_data.cc[i] <= 13))
		{
			j = i;
			while (data->map_data.cc[i] == ' ' || (data->map_data.cc[i] >= 9
					&& data->map_data.cc[i] <= 13))
				i++;
			temp = ft_strndup_gnl(data->map_data.cc, j);
			temp2 = ft_strdup(data->map_data.cc);
			free (data->map_data.cc);
			data->map_data.cc = ft_strjoin(temp, temp2 + i);
			return (free(temp), free(temp2), clean_color_cc(data));
		}
		else
			i++;
	}
}

void	clean_color_cf(t_data *data)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;

	i = 0;
	while (data->map_data.cf[i])
	{
		if (data->map_data.cf[i] == ' ' || (data->map_data.cf[i] >= 9
				&& data->map_data.cf[i] <= 13))
		{
			j = i;
			while (data->map_data.cf[i] == ' ' || (data->map_data.cf[i] >= 9
					&& data->map_data.cf[i] <= 13))
				i++;
			temp = ft_strndup_gnl(data->map_data.cf, j);
			temp2 = ft_strdup(data->map_data.cf);
			free (data->map_data.cf);
			data->map_data.cf = ft_strjoin(temp, temp2 + i);
			return (free(temp), free(temp2), clean_color_cf(data));
		}
		else
			i++;
	}
}

void	check_value_color(t_data *data)
{
	char	**value;
	int		i;
	int		val;

	i = 0;
	value = ft_split(data->map_data.cc, ',');
	while (value[i])
	{
		val = ft_atoi(value[i]);
		if (val < 0 || val > 255)
			return (free_array(value), ft_error_data(data, 3));
		i++;
	}
	free_array(value);
	value = ft_split(data->map_data.cf, ',');
	while (value[i])
	{
		val = ft_atoi(value[i]);
		if (val < 0 || val > 255)
			return (free_array(value), ft_error_data(data, 3));
		i++;
	}
	free_array(value);
}

void	check_char_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_data.map[y])
	{
		x = 0;
		while (data->map_data.map[y][x])
		{
			if (data->map_data.map[y][x] == ' ' || data->map_data.map[y][x] == '1'
			|| data->map_data.map[y][x] == '0' || data->map_data.map[y][x] == 'N'
			|| data->map_data.map[y][x] == 'S' || data->map_data.map[y][x] == 'E'
			|| data->map_data.map[y][x] == 'W')
				x++;
			else
				ft_error_data(data, 4);
		}
		y++;
	}
	data->map_data.nb_row = y;
}

int	check_in_map(char **map_cpy, int x, int y, t_data *data)
{
	if (x == 0 || x == ft_strlen_gnl(map_cpy[y]) - 1 || y == 0 || y == data->map_data.nb_row - 1)
		return (1);
	if (x + 1 > ft_strlen_gnl(map_cpy[y - 1]) || x + 1 > ft_strlen_gnl(map_cpy[y + 1]))
		return (1);
	return (0);
}

void	check_angle(char **map_cpy, int y, int x, t_data *data)
{
	/* if (map_cpy[y - 1][x] == ' ' || map_cpy[y + 1][x] == ' ')
		data->map_data.valid_map = 0;
	if (map_cpy[y][x - 1] == ' ' || map_cpy[y][x + 1] == ' ')
		data->map_data.valid_map = 0; */
	if (map_cpy[y - 1][x] == ' ' || map_cpy[y + 1][x] == ' ' || map_cpy[y][x - 1] == ' ' || map_cpy[y][x + 1] == ' ' || map_cpy[y - 1][x - 1] == ' ' || map_cpy[y - 1][x + 1] == ' ' || map_cpy[y + 1][x - 1] == ' ' || map_cpy[y + 1][x + 1] == ' ')
		data->map_data.valid_map = 0;
}

void	is_closed(char **map_cpy, int y, int x, t_data *data)
{
	if (map_cpy[y][x] != '0')
		return ;
	if (check_in_map(map_cpy, x, y, data) == 1)
	{
		data->map_data.valid_map = 0;
		return ;
	}
	map_cpy[y][x] = '1';
	check_angle(map_cpy, y, x, data);
	is_closed(map_cpy, y - 1, x, data);
	is_closed(map_cpy, y + 1, x, data);
	is_closed(map_cpy, y, x - 1, data);
	is_closed(map_cpy, y, x + 1, data);
}

void	check_wall(t_data *data)
{
	int		x;
	int		y;
	char	**map_cpy;

	y = -1;
	map_cpy = malloc(sizeof(char *) * data->map_data.nb_row + 1);
	while (data->map_data.map[++y])
		map_cpy[y] = ft_strdup(data->map_data.map[y]);
	map_cpy[y] = NULL;
	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == '0')
				is_closed(map_cpy, y, x, data);
			if (data->map_data.valid_map == 0)
				return (printf("Error\nMap not close\n"), free_array(map_cpy));
			x++;
		}
		y++;
	}
	int i = 0;
	while (i < 14)
	{
		printf("ligne cpy %d : %s\n", i, map_cpy[i]);
		i++;
	}
	free_array(map_cpy);
}

int	parsing(char **av, t_data *data)
{
	init_map_data(data);
	read_option(av, data);
	clean_color_cc(data);
	clean_color_cf(data);
	check_color(data);
	check_value_color(data);

	check_char_map(data);
	check_wall(data);

	return (0);


	//is_map_rectangle(data);
	//check_walls_and_char(data);
	//is_path_valid(av, data);
}

void	convert_hexa(long int nbr)
{
	char *base = "0123456789abcdef";

	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr *= -1;
	}
	if (nbr > basenbr)
		ft_putnbr((nbr / basenbr), basenbr, count);
	ft_putchar(base[nbr % basenbr], count);
}

char	*convert_color(char *col)
{
	char		**color;
	char		*res;
	long int	num;
	int			i;

	color = ft_split(col, ',');
	res = NULL;
	res = ft_strdup("0x");
	i = 0;
	num = ft_atoi(col[i]);
	res = ft_strjoin(res, convert_hexa(num));
}
