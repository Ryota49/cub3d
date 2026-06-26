/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:57:24 by byonis            #+#    #+#             */
/*   Updated: 2026/06/26 10:29:09 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_hook(int key, void *param)
{
	// ESC = 41
	// W = 26
	// A = 4
	// S = 22
	// D = 7
	if (key == 41)
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