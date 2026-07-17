/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:07:33 by byonis            #+#    #+#             */
/*   Updated: 2026/07/17 12:56:07 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	put_pixel_to_buffer(t_game *g, int x, int y, mlx_color color)
{
	if (x >= 0 && x < g->screen_w && y >= 0 && y < g->screen_h)
		g->screen_pixels[y * g->screen_w + x] = color;
}

void	draw_column(t_game *g, t_ray *ray, int x, int side)
{
	int			y;
	int			tex_x;
	int			tex_y;
	float		wall_x;
	void		*texture;
	float		step;
	float		tex_pos;
	mlx_color	color;
	
	if (side == 0)
	{
		if (ray->step_x > 0)
			texture = g->tex_west;
		else
			texture = g->tex_east;
		wall_x = g->player.pos_y + ray->wall_dist * (g->player.dir_y + g->player.plane_y * ray->camera_x);
	}
	else
	{
		if (ray->step_y > 0)
			texture = g->tex_north;
		else
			texture = g->tex_south;
		wall_x = g->player.pos_x + ray->wall_dist * (g->player.dir_x + g->player.plane_x * ray->camera_x);
	}
	wall_x -= floorf(wall_x);
	tex_x = (int)(wall_x * (float)g->img_width);
	if ((side == 0 && ray->step_x > 0) || (side == 1 && ray->step_y < 0))
		tex_x = g->img_width -tex_x - 1;
	y = 0;
	while (y < ray->pixel_start)
	{
		put_pixel_to_buffer(g, x, y, (mlx_color){.rgba = 0x333333FF});
		y++;
	}
	step = 1.0 * g->img_height / (ray->pixel_end - ray->pixel_start);
	tex_pos = (ray->pixel_start - g->screen_h / 2 + (ray->pixel_end - ray->pixel_start) / 2) * step;
	while (y <= ray->pixel_end)
	{
		tex_y = (int)tex_pos % g->img_height;
		tex_pos += step;
		color = mlx_get_image_pixel(g->mlx, texture, tex_x, tex_y);
		put_pixel_to_buffer(g, x, y, color);
		y++;
	}
	while (y < g->screen_h)
	{
		put_pixel_to_buffer(g, x, y, (mlx_color){.rgba = 0x666666FF});
		y++;
	}
	
	// int		color;

	// y = 0;
	// while (y < ray->pixel_start)
	// {
	// 	mlx_pixel_put(g->mlx, g->win, x, y, (mlx_color){ .rgba = 0x333333});
	// 	y++;
	// }
	// if (side == 1)
	// 	color = 0x00FF00;
	// else
	// 	color = 0x007700;
	// while (y <= ray->pixel_end)
	// {
	// 	mlx_pixel_put(g->mlx, g->win, x, y, (mlx_color){ .rgba = color});
	// 	y++;
	// }
	// while (y < g->screen_h)
	// {
	// 	mlx_pixel_put(g->mlx, g->win, x, y, (mlx_color){ .rgba = 0x666666});
	// 	y++;
	// }
}

void	render(void *param)
{
	t_game	*g;
	int		x;
	int		side;
	float	wall_dist;

	g = (t_game *)param;
	update_movement(g);
	mlx_clear_window(g->mlx, g->win, (mlx_color){ .rgba = 0x000000FF });
	x = 0;
	while (x < g->screen_w)
	{
		init_ray(g, &g->ray, x);
		side = perform_dda(g, &g->ray);
		wall_dist = calculate_wall_dist(&g->ray, side);
		g->ray.wall_dist = wall_dist;
		calculate_pixel_start_end(g, &g->ray, wall_dist);
		draw_column(g, &g->ray, x, side);
		x++;
	}
	mlx_set_image_region(g->mlx, g->screen_img, 0, 0, g->screen_w, g->screen_h, g->screen_pixels);
	mlx_put_image_to_window(g->mlx, g->win, g->screen_img, 0, 0);
}