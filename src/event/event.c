/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:57:24 by byonis            #+#    #+#             */
/*   Updated: 2026/07/20 09:38:11 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_down_hook(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == W_KEY)
		g->keys.w = 1;
	if (key == S_KEY)
		g->keys.s = 1;
	if (key == A_KEY)
		g->keys.a = 1;
	if (key == D_KEY)
		g->keys.d = 1;
	if (key == ROT_RIGHT)
		g->keys.right = 1;
	if (key == ROT_LEFT)
		g->keys.left = 1;
	if (key == ESC_KEY)
		mlx_loop_end(g->mlx);
}

void	key_up_hook(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == W_KEY)
		g->keys.w = 0;
	if (key == S_KEY)
		g->keys.s = 0;
	if (key == A_KEY)
		g->keys.a = 0;
	if (key == D_KEY)
		g->keys.d = 0;
	if (key == ROT_RIGHT)
		g->keys.right = 0;
	if (key == ROT_LEFT)
		g->keys.left = 0;
}

void	window_hook(int event, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (event == 0)
		mlx_loop_end(g->mlx);
}
