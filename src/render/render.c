/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:07:33 by byonis            #+#    #+#             */
/*   Updated: 2026/07/02 15:05:11 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_column(t_game *g, t_ray *ray, int x, int side)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < ray->pixel_start)
	{
		mlx_pixel_put(g->mlx, g->win, x, y, (mlx_color){ .rgba = 0x333333});
		y++;
	}
	if (side = 1)
		color = 0x00FF00;
	else
		color = 0x007700;
	while (y <= ray->pixel_end)
	{
		mlx_pixel_put(g->mlx, g->win, x, y, (mlx_color){ .rgba = color});
		y++;
	}
	while (y < g->screen_h)
	{
		mlx_pixel_put(g->mlx, g->win, x, y, (mlx_color){ .rgba = 0x666666});
		y++;
	}
}

void	render(t_game *g, t_ray *ray)
{
	int		x;
	int		side;
	float	wall_dist;

	x = 0;
	while (x < g->screen_w)
	{
		init_ray(g, ray, x);
		side = perform_dda(g, ray);
		wall_dist = calculate_wall_dist(ray, side);
		calculate_pixel_start_end(g, ray, wall_dist);
		draw_column(g, ray, x, side);
	}
}