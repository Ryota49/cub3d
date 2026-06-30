/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:17:44 by byonis            #+#    #+#             */
/*   Updated: 2026/06/30 15:14:08 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_step_side(t_game *g, t_ray *ray, float ray_dir_x, float ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (g->player.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x =
			(ray->map_x + 1.0 - g->player.pos_x) * ray->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (g->player.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y =
			(ray->map_y + 1.0 - g->player.pos_y) * ray->delta_dist_y;
	}
}

void	init_ray(t_game *g, t_ray *ray, int x)
{
	float	ray_dir_x;
	float	ray_dir_y;

	ray->camera_x = 2.0 * x / (float)g->screen_w - 1.0;
	ray_dir_x = g->player.dir_x + g->player.plane_x * ray->camera_x;
	ray_dir_y = g->player.dir_y + g->player.plane_y * ray->camera_x;
	if (ray_dir_x == 0)
		return (INFINITY);
	else
		ray->delta_dist_x = fabs(1.0 / ray_dir_x);
	if (ray_dir_y == 0)
		return (INFINITY);
	else
		ray->delta_dist_y = fabs(1.0 / ray_dir_y);
}
