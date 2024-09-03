#include "../../inc/cub3d.h"

void	ft_error(int flag)
{
	errno = 1;
	if (flag == 0)
		perror("Error\nInvalid arguments\n");
	if (flag == 1)
		perror("Error\nWrong extension, only .cub extension\n");
	if (flag == 2)
		perror("Error\nFile can't be opened\n");
	if (flag == 3)
		perror("Error\nFile is empty\n");
	exit (1);
}

void	ft_error_data(t_data *data, int flag)
{
	errno = 1;
	if (flag == 0)
		perror("Error\nWrong path detected\n");
	if (flag == 1)
		perror("");
	if (flag == 2)
		perror("");
	if (flag == 3)
		perror("");
	if (flag == 4)
		perror("");
	if (flag == 5)
		perror("");
	if (flag == 6)
		perror("");
	if (flag == 7)
		perror("");
	if (flag == 8)
		perror("");	
	free_array(data->map_data.map);
	free_char_option(data);
	exit (1);
}

void	free_char_option(t_data *data)
{
	if (data->map_data.NO != NULL)
		free(data->map_data.NO);
	else if (data->map_data.SO != NULL)
		free(data->map_data.SO);
	else if (data->map_data.WE != NULL)
		free(data->map_data.WE);
	else if (data->map_data.EA != NULL)
		free(data->map_data.EA);
	else if (data->map_data.CC != NULL)
		free(data->map_data.CC);
	else if (data->map_data.CF != NULL)
		free(data->map_data.CF);
}
