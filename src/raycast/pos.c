#include "../../inc/cub3d.h"

void	*init_pos(int type)
{
	t_coord	*coord;
	t_pos	*pos;
	
	coord = malloc(sizeof(t_coord));
	pos = malloc(sizeof(t_pos));
	coord->x = 0;
	coord->y = 0;
	pos->x = 0;
	pos->y = 0;
	if (type == 0)
		return (free(pos), coord);
	if (type == 1)
		return (free(coord), pos);
	return (free(pos), free(coord), NULL);
}
