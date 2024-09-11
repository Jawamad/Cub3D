#include "../../inc/cub3d.h"

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
