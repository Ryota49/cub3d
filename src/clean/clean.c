/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:17:16 by byonis            #+#    #+#             */
/*   Updated: 2026/07/17 12:03:46 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean_game(t_game *g)
{
	if (g->texture_n)
		free(g->texture_n);
	if (g->texture_s)
		free(g->texture_s);
	if (g->texture_w)
		free(g->texture_w);
	if (g->texture_e)
		free(g->texture_e);
	if (g->tex_north)
		mlx_destroy_image(g->mlx, g->tex_north);
	if (g->tex_south)
		mlx_destroy_image(g->mlx, g->tex_south);
	if (g->tex_west)
		mlx_destroy_image(g->mlx, g->tex_west);
	if (g->tex_east)
		mlx_destroy_image(g->mlx, g->tex_east);
	if (g->screen_img)
		mlx_destroy_image(g->mlx, g->screen_img);
	if (g->screen_pixels)
		free(g->screen_pixels);
	if (g->map)
	{
		free_splitter(g->map);
		g->map = NULL;
	}
	if (g->mlx && g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		mlx_destroy_context(g->mlx);
}

void	clean_parsing(t_utils_parsing *pars)
{
	if (!pars)
		return ;
	if (pars->real_map == pars->game.map)
		pars->real_map = NULL;
	clean_game(&pars->game);
	if (pars->splitter)
		free_splitter(pars->splitter);
	if (pars->line)
		free(pars->line);
	if (pars->real_map)
		free_splitter(pars->real_map);
	if (pars->cpy_map)
		free_splitter(pars->cpy_map);
	get_next_line(-1);
}