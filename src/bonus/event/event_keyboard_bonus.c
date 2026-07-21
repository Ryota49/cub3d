/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:33:37 by byonis            #+#    #+#             */
/*   Updated: 2026/07/21 10:05:03 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	is_wall(t_game *g, float x, float y)
{
	if (x < 0 || y < 0 || !g->map[(int)y])
		return (1);
	if ((int)x >= (int)ft_strlen(g->map[(int)y]))
		return (1);
	if (g->map[(int)y][(int)x] == '1' || g->map[(int)y][(int)x] == ' ')
		return (1);
	return (0);
}

static void	rotate_left(t_game *g)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cosf(-ROT_SPEED)
		- g->player.dir_y * sinf(-ROT_SPEED);
	g->player.dir_y = old_dir_x * sinf(-ROT_SPEED)
		+ g->player.dir_y * cosf(-ROT_SPEED);
	g->player.plane_x = g->player.plane_x * cosf(-ROT_SPEED)
		- g->player.plane_y * sinf(-ROT_SPEED);
	g->player.plane_y = old_plane_x * sinf(-ROT_SPEED)
		+ g->player.plane_y * cosf(-ROT_SPEED);
}

static void	rotate_right(t_game *g)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cosf(ROT_SPEED)
		- g->player.dir_y * sinf(ROT_SPEED);
	g->player.dir_y = old_dir_x * sinf(ROT_SPEED)
		+ g->player.dir_y * cosf(ROT_SPEED);
	g->player.plane_x = g->player.plane_x * cosf(ROT_SPEED)
		- g->player.plane_y * sinf(ROT_SPEED);
	g->player.plane_y = old_plane_x * sinf(ROT_SPEED)
		+ g->player.plane_y * cosf(ROT_SPEED);
}

static void	move_player(t_game *g, float *new_x, float *new_y)
{
	if (g->keys.w)
	{
		*new_x += g->player.dir_x * MOVE_SPEED;
		*new_y += g->player.dir_y * MOVE_SPEED;
	}
	if (g->keys.s)
	{
		*new_x -= g->player.dir_x * MOVE_SPEED;
		*new_y -= g->player.dir_y * MOVE_SPEED;
	}
	if (g->keys.a)
	{
		*new_x += g->player.dir_y * MOVE_SPEED;
		*new_y -= g->player.dir_x * MOVE_SPEED;
	}
	if (g->keys.d)
	{
		*new_x -= g->player.dir_y * MOVE_SPEED;
		*new_y += g->player.dir_x * MOVE_SPEED;
	}
}

void	update_movement(t_game *g)
{
	float	new_x;
	float	new_y;

	new_x = g->player.pos_x;
	new_y = g->player.pos_y;
	move_player(g, &new_x, &new_y);
	if (!is_wall(g, new_x, g->player.pos_y))
		g->player.pos_x = new_x;
	if (!is_wall(g, g->player.pos_x, new_y))
		g->player.pos_y = new_y;
	if (g->keys.left)
		rotate_left(g);
	if (g->keys.right)
		rotate_right(g);
	update_movement_mouse(g);
}
