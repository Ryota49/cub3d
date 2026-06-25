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
}
