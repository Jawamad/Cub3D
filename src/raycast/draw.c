#include "../../inc/cub3d.h"

void draw_line(t_data *data, t_coord start, t_coord end, int color)
{
	t_coord d;
	t_coord s;
	int err;
	int e2;

	d.x = abs_val(end.x - start.x);
	d.y = abs_val(end.y - start.y);
	if (start.x < end.x)
		s.x = 1;
	else
		s.x = -1;
	if (start.y < end.y)
		s.y = 1;
	else
		s.y = -1;
	err = d.x - d.y; 
	while (1)
	{
        mlx_pixel_put(data->mlx, data->mlx_win, start.x, start.y, color);  // Dessine le pixel courant
        if (start.x == end.x && start.y == end.y)
            break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            start.y += sy;
        }
    }
}
