/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:57:24 by byonis            #+#    #+#             */
/*   Updated: 2026/07/03 14:12:13 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_hook(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	move_forward_or_move_back(g, key);
	if (key == ESC_KEY)
		mlx_loop_end((mlx_context)param);
}

// void	mouse_hook(int button, void *param)
// {
// 	// CLIC GAUCHE = 1
// 	// CLIC MOLLETTE = 2
// 	// CLIC DROIT = 3
// }

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}