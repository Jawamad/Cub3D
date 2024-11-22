#ifndef CUB3D_H
# define CUB3D_H

/* Library */

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

# define PI 	3.14159
# define FOV	60

//# define BUFFER_SIZE 42

# define TILE_SIZE 		64
# define SCR_WIDTH 		1900
# define SCR_HEIGHT 	1000
# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define BACK			115
# define RIGHT			100
//azerty :
# define FORWARD		122
# define LEFT			113
//qwerty :
//# define FORWARD		119
//# define LEFT			97

/* Structure */

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		 line_length;
	int		endian;
	int		height;        
	int		width;
	char	*path;
}	t_texture;

typedef struct s_ray
{
	double	r_distance;
	double	r_angle;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	int		flag;
}	t_ray;

typedef struct s_player
{
	int		map_x;
	int		map_y;
	int		p_x;
	int		p_y;
	float	fov_rad;
	int		p_speed;
	double	p_angle;
}	t_player;

typedef struct s_data{
	void			*mlx;
	void			*win;

	t_img			img_screen;

	char			**map;
	int				nb_column;
	int				nb_row;
	int				p_count;
	int				width;
	int				height;

	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*cc;
	char			*cf;
	int				count_line;
	int				valid_map;

	t_player		player;
	t_ray			ray;
}		t_data;

/* Fonctions */

/* parsing/parsing.c */
void	init_map_data(t_data *data);
void	read_map(int file, t_data *data);
void	read_option(char **av, t_data *data);
int		parsing(char **av, t_data *data);

/* parsing/parsing_check_file.c */
int		check_exten(char *av);
void	line_cardinal(char *line, t_data *data, int flag);
void	check_line(char *line, t_data *data);
void	check_char_map(t_data *data);

/* parsing/parsing_map_closed.c */
int		check_in_map(char **map_cpy, int x, int y, t_data *data);
void	check_angle(char **map_cpy, int y, int x, t_data *data);
void	is_closed(char **map_cpy, int y, int x, t_data *data);
void	check_wall(t_data *data);

/* parsing/parsing_color.c */
void	check_color(t_data *data);
void	clean_color_cc(t_data *data);
void	clean_color_cf(t_data *data);
void	check_value_color(t_data *data);
void	line_color(char *line, t_data *data, int flag);

/* utils/ft_error.c */
void	ft_error(int flag);
void	ft_error_data(t_data *data, int flag);
void	free_char_option(t_data *data);

/* utils/ft_utils.c */
void	free_array(char **array);
int		rgb_to_hex(char *rgb_str);

#endif