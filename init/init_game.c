/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:51:40 by byonis            #+#    #+#             */
/*   Updated: 2026/06/24 13:23:07 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_game(t_game *g)
{
	mlx_window_create_info info;
	
	if (!g)
		return (0);
	g->screen_w = 1280;
	g->screen_h = 720;
	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	info.title = "cub3d";
	info.width = g->screen_w;
	info.height= g->screen_h;
	g->win = mlx_new_window(g->mlx, &info);
	if (!g->win)
	{
		clean(g);
		return (0);
	}
		
}
