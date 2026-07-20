/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:06:46 by byonis            #+#    #+#             */
/*   Updated: 2026/07/20 11:29:15 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	apply_mouse_rotation(t_game *g, int delta_x)
{
	float	angle;
	float	old_dir_x;
	float	old_plane_x;

	angle = delta_x * MOUSE_SPEED;
	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cosf(angle)
		- g->player.dir_y * sinf(angle);
	g->player.dir_y = old_dir_x * sinf(angle)
		+ g->player.dir_y * cosf(angle);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cosf(angle)
		- g->player.plane_y * sinf(angle);
	g->player.plane_y = old_plane_x * sinf(angle)
		+ g->player.plane_y * cosf(angle);
}

void	update_movement_mouse(t_game *g)
{
	int		mouse_x;
	int		mouse_y;
	int		delta_x;

	mlx_mouse_get_pos(g->mlx, &mouse_x, &mouse_y);
	delta_x = mouse_x - (WINDOW_WIDTH / 2);
	if (delta_x != 0)
		apply_mouse_rotation(g, delta_x);
	if (delta_x != 0 || mouse_y != (WINDOW_HEIGHT / 2))
		mlx_mouse_move(g->mlx, g->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}
