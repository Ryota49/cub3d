/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_dist_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:51:43 by byonis            #+#    #+#             */
/*   Updated: 2026/07/21 12:38:38 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	calculate_wall_dist(t_ray *ray, int side)
{
	if (side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	else
		return (ray->side_dist_y - ray->delta_dist_y);
}

void	calculate_pixel_start_end(t_game *g, t_ray *ray, float perp_wall_dist)
{
	int	line_height;

	line_height = (int)(g->screen_h / perp_wall_dist);
	ray->line_height = line_height;
	ray->pixel_start = -line_height / 2 + g->screen_h / 2;
	if (ray->pixel_start < 0)
		ray->pixel_start = 0;
	ray->pixel_end = line_height / 2 + g->screen_h / 2;
	if (ray->pixel_end >= g->screen_h)
		ray->pixel_end = g->screen_h -1;
}
