/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/26 18:01:37 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_color_f(t_utils_parsing *parsing)
{
	if (parsing->splitter[2] != NULL)
		err_free("Error\nUnknown or multiple token in line\n", parsing);
	parsing->count_f++;
}

void	check_color_c(t_utils_parsing *parsing)
{
	if (parsing->splitter[2] != NULL)
		err_free("Error\nUnknown or multiple token in line\n", parsing);
	parsing->count_c++;
}
