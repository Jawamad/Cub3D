#ifndef CUB3D_H
# define CUB3D_H

/* Library */

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

/* Structure */

#define TILE 16;

typedef struct s_coord{
	int	x;
	int	y;
}	t_coord;

typedef struct s_pos{
	double	x;
	double	y;
}	t_pos;

typedef struct s_player{
	t_pos	ppos;
	t_pos	pdir;
}	t_player;

typedef struct s_map_data{
	char			**map;
	unsigned int	nb_column;
	unsigned int	nb_row;
	int				p_count;
	int				width;
	int				height;
	t_player		player;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*cc;
	char			*cf;
	int				count_line;
}	t_map_data;

typedef struct s_data{
	void			*mlx;
	void			*mlx_win;
//	int				nb_moves;
	t_map_data		map_data;
//	t_img			img;
}		t_data;

/* Fonctions */

/* parsing/parsing.c */
int		check_exten(char *av);
void	init_map_data(t_data *data);
void	read_map(int file, t_data *data);
void	read_option(char **av, t_data *data);
int		parsing(char **av, t_data *data);
void	check_line(char *line, t_data *data);
void	line_color(char *line, t_data *data, int flag);
void	line_cardinal(char *line, t_data *data, int flag);
void	check_color(t_data *data);
void	clean_color_cc(t_data *data);
void	clean_color_cf(t_data *data);
void	check_value_color(t_data *data);

/* utils/ft_error.c */
void	ft_error(int flag);
void	ft_error_data(t_data *data, int flag);
void	free_char_option(t_data *data);

/* utils/ft_utils.c */
void	free_array(char **array);

/* raycast/minimap.c */
int		set_minimap(t_data *data);
void	put_tile_mmap(t_pos map_pen, t_pos map_reader, t_data *data);
void	paint_tile_mmap(int x, int y, int color,t_data *data);
int		is_player_mmap(char c);
int		is_wall_mmap(char c);
int		is_floor_mmap(char c);
t_pos	search_player(t_data *data);

/* raycast/pos.c */
t_pos	init_pos(void);
t_coord	init_coord(void);

/* raycast/mlxinit.c */

void	init_win(t_data *data);
void	init_map(t_data *data);

#endif