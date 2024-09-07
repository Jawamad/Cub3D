#include "../inc/cub3d.h"

void	*init_pos(int type)
{
	t_coord	coord;
	t_pos	pos;

	if (type == 0)
	{
		coord.x = 0;
		coord.y = 0;
		return (&coord);
	}
	if (type == 1)
	{
		pos.x = 0;
		pos.y = 0;
		return (&pos);
	}
}
