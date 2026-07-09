/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:22:45 by byonis            #+#    #+#             */
/*   Updated: 2026/07/09 10:52:18 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	perform_dda(t_game *g, t_ray *ray)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			side = 1;
		}
		if (ray->map_y < 0 || !g->map[ray->map_y])
			break ;
		if (ray->map_x < 0 || !g->map[ray->map_x])
			break ;
		if (g->map[ray->map_y][ray->map_x] == ' ' || g->map[ray->map_y][ray->map_x] == '\t')
			break ;
		if (g->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	return (side);
}
