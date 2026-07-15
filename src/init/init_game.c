/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:51:40 by byonis            #+#    #+#             */
/*   Updated: 2026/07/14 15:43:25 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_game(t_game *g, t_utils_parsing *parsing)
{
	mlx_window_create_info	info;

	if (!g)
		return (0);
	g->screen_w = 1280;
	g->screen_h = 720;
	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	ft_bzero(&info, sizeof(mlx_window_create_info));
	info.title = "cub3d";
	info.width = g->screen_w;
	info.height= g->screen_h;
	g->win = mlx_new_window(g->mlx, &info);
	if (!g->win)
	{
		clean_game(g);
		return (0);
	}
	g->img_height = 64;
	g->img_width = 64;
	g->tex_north = mlx_new_image_from_file(g->mlx, g->texture_n, &g->img_width, &g->img_height);
	g->tex_south = mlx_new_image_from_file(g->mlx, g->texture_s, &g->img_width, &g->img_height);
	g->tex_east = mlx_new_image_from_file(g->mlx, g->texture_e, &g->img_width, &g->img_height);
	g->tex_west = mlx_new_image_from_file(g->mlx, g->texture_w, &g->img_width, &g->img_height);
	if (!g->tex_north || !g->tex_south || !g->tex_east || !g->tex_west)
	{
		handle_error("Error: Unable to load PNG textures.");
		clean_parsing(parsing);
		exit(1);
	}	
	g->map = parsing->real_map;
	player_pos(g);
	return (1);
}
