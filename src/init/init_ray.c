/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:17:44 by byonis            #+#    #+#             */
/*   Updated: 2026/06/29 14:20:42 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_game *g, t_ray *ray, int x)
{
	float	ray_dir_x;
	float	ray_dir_y;

	ray->camera_x = 2.0 * x / (float)g->screen_w - 1.0;
	ray_dir_x = g->player.dir_x + g->player.plane_x * ray->camera_x;
	ray_dir_y = g->player.dir_y + g->player.plane_y * ray->camera_x;
}