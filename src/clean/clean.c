/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:17:16 by byonis            #+#    #+#             */
/*   Updated: 2026/07/09 14:00:03 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean_game(t_game *g)
{
	if (g->mlx && g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		mlx_destroy_context(g->mlx);
	if (g->texture_n)
		free(g->texture_n);
	if (g->texture_s)
		free(g->texture_s);
	if (g->texture_w)
		free(g->texture_w);
	if (g->texture_e)
		free(g->texture_e);
}

void	clean_parsing(t_utils_parsing *pars)
{
	if (pars)
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