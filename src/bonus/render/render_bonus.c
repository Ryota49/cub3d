/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:07:33 by byonis            #+#    #+#             */
/*   Updated: 2026/07/21 10:05:03 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	*get_texture_data(t_game *g, t_ray *ray, int side, int *tex_x)
{
	float		wall_x;
	void		*texture;

	texture = g->tex_east;
	if (side == 0 && ray->step_x > 0)
		texture = g->tex_west;
	else if (side == 1 && ray->step_y > 0)
		texture = g->tex_north;
	else if (side == 1)
		texture = g->tex_south;
	if (side == 0)
		wall_x = g->player.pos_y + ray->wall_dist
			* (g->player.dir_y + g->player.plane_y * ray->camera_x);
	else
		wall_x = g->player.pos_x + ray->wall_dist
			* (g->player.dir_x + g->player.plane_x * ray->camera_x);
	wall_x -= floorf(wall_x);
	*tex_x = (int)(wall_x * (float)g->img_width);
	if ((side == 0 && ray->step_x > 0) || (side == 1 && ray->step_y < 0))
		*tex_x = g->img_width - *tex_x - 1;
	return (texture);
}

static void	draw_wall(t_game *g, t_ray *ray, int x, void *texture)
{
	int			y;
	int			tex_y;
	float		step;
	float		tex_pos;
	mlx_color	color;

	step = 1.0 * g->img_height / ray->line_height;
	tex_pos = (ray->pixel_start - g->screen_h / 2 + ray->line_height / 2)
		* step;
	y = ray->pixel_start;
	while (y <= ray->pixel_end)
	{
		tex_y = (int)tex_pos % g->img_height;
		tex_pos += step;
		color = mlx_get_image_pixel(g->mlx, texture, ray->map_x, tex_y);
		put_pixel_to_buffer(g, x, y, color);
		y++;
	}
}

void	draw_column(t_game *g, t_ray *ray, int x, int side)
{
	int		y;
	int		tex_x;
	int		saved_start;
	void	*texture;

	texture = get_texture_data(g, ray, side, &tex_x);
	y = 0;
	while (y < ray->pixel_start)
	{
		put_pixel_to_buffer(g, x, y, color_to_mlx_color(g->ceiling));
		y++;
	}
	saved_start = ray->pixel_start;
	ray->map_x = tex_x;
	draw_wall(g, ray, x, texture);
	ray->pixel_start = saved_start;
	y = ray->pixel_end + 1;
	while (y < g->screen_h)
	{
		put_pixel_to_buffer(g, x, y, color_to_mlx_color(g->floor));
		y++;
	}
}

void	render(void *param)
{
	t_game	*g;
	int		x;
	int		side;
	float	wall_dist;

	g = (t_game *)param;
	update_movement(g);
	mlx_clear_window(g->mlx, g->win, (mlx_color){.rgba = 0x000000FF});
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
	mlx_set_image_region(
		g->mlx, g->screen_img, 0, 0, g->screen_w, g->screen_h, g->screen_pix);
	mlx_put_image_to_window(g->mlx, g->win, g->screen_img, 0, 0);
}
