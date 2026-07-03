/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:33:37 by byonis            #+#    #+#             */
/*   Updated: 2026/07/03 13:58:31 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_wall(t_game *g, float x, float y)
{
	if (g->map[(int)y][(int)x] == 1)
		return (1);
	return (0);
}

void	move_forward_or_move_back(t_game *g, int key)
{
	float	new_x;
	float	new_y;

	new_x = g->player.pos_x;
	new_y = g->player.pos_y;
	if (key == W_KEY)
	{
		new_x += g->player.dir_x * MOVE_SPEED;
		new_y += g->player.dir_y * MOVE_SPEED;
	}
	if (key == S_KEY)
	{
		new_x -= g->player.dir_x * MOVE_SPEED;
		new_y -= g->player.dir_y * MOVE_SPEED;
	}
	if (!is_wall(g, new_x, new_y))
	{
		g->player.pos_x = new_x;
		g->player.pos_y = new_y;
	}
}
