/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_structure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/23 16:52:49 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialise_parsing(t_utils_parsing *parsing)
{
	parsing->count_no = 0;
	parsing->count_so = 0;
	parsing->count_we = 0;
	parsing->count_ea = 0;
	parsing->count_f = 0;
	parsing->count_c = 0;
	parsing->header_done = 0;
	parsing->start_map = 0;
	parsing->line = NULL;
	parsing->splitter = NULL;
	parsing->fd = 0;
	parsing->game.texture_n = NULL;
	parsing->game.texture_s = NULL;
	parsing->game.texture_w = NULL;
	parsing->game.texture_e = NULL;
	parsing->line_read = 0;
	parsing->height_map = 0;
	parsing->map.count_n = 0;
	parsing->map.count_s = 0;
	parsing->map.count_w = 0;
	parsing->map.count_e = 0;
	parsing->width_max = 0;
}
