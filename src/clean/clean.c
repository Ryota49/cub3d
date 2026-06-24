/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:17:16 by byonis            #+#    #+#             */
/*   Updated: 2026/06/24 13:50:17 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		mlx_destroy_context(g->mlx);
}
