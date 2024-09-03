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

typedef struct s_pos{
	int				x;
	int				y;
}	t_pos;

typedef struct s_map_data{
	char			**map;
	unsigned int	nb_column;
	unsigned int	nb_row;
	int				p_count;
	int				width;
	int				height;
	t_pos			p_pos;

	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*CC;
	char			*CF;
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
void	read_option(char **av, t_data *data);
int		parsing(char **av, t_data *data);

/* error/ft_error.c */
void	ft_error(int flag);
void	ft_error_data(t_data *data, int flag);


#endif