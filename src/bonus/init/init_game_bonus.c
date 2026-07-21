/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:51:40 by byonis            #+#    #+#             */
/*   Updated: 2026/07/21 10:05:03 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	load_textures(t_game *g, t_utils_parsing *parsing)
{
	g->img_height = 960;
	g->img_width = 960;
	g->tex_north = mlx_new_image_from_file(
			g->mlx, g->texture_n, &g->img_width, &g->img_height);
	g->tex_south = mlx_new_image_from_file(
			g->mlx, g->texture_s, &g->img_width, &g->img_height);
	g->tex_east = mlx_new_image_from_file(
			g->mlx, g->texture_e, &g->img_width, &g->img_height);
	g->tex_west = mlx_new_image_from_file(
			g->mlx, g->texture_w, &g->img_width, &g->img_height);
	if (!g->tex_north || !g->tex_south || !g->tex_east || !g->tex_west)
	{
		handle_error("Error: Unable to load PNG textures.");
		clean_parsing(parsing);
		exit(1);
	}
	return (1);
}

static int	init_mlx_window(t_game *g)
{
	mlx_window_create_info	info;

	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	g->screen_w = WINDOW_WIDTH;
	g->screen_h = WINDOW_HEIGHT;
	ft_bzero(&info, sizeof(mlx_window_create_info));
	info.title = "cub3d";
	info.width = g->screen_w;
	info.height = g->screen_h;
	g->win = mlx_new_window(g->mlx, &info);
	if (!g->win)
		return (0);
	g->screen_pix = malloc(g->screen_w * g->screen_h * sizeof(mlx_color));
	if (!g->screen_pix)
		return (0);
	g->screen_img = mlx_new_image(g->mlx, g->screen_w, g->screen_h);
	if (!g->screen_img)
		return (0);
	return (1);
}

int	init_game(t_game *g, t_utils_parsing *parsing)
{
	if (!g)
		return (0);
	g->screen_w = WINDOW_WIDTH;
	g->screen_h = WINDOW_HEIGHT;
	if (!init_mlx_window(g))
	{
		clean_game(g);
		return (0);
	}
	load_textures(g, parsing);
	g->map = parsing->real_map;
	player_pos(g);
	return (1);
}
