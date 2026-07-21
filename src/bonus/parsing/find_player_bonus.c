/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 23:52:50 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/21 12:37:56 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_count(t_utils_parsing *parsing)
{
	if (parsing->map.count_e == 1 && parsing->map.count_w == 0
		&& parsing->map.count_n == 0 && parsing->map.count_s == 0)
		create_copy_map(parsing);
	else if (parsing->map.count_e == 0 && parsing->map.count_w == 1
		&& parsing->map.count_n == 0 && parsing->map.count_s == 0)
		create_copy_map(parsing);
	else if (parsing->map.count_e == 0 && parsing->map.count_w == 0
		&& parsing->map.count_n == 1 && parsing->map.count_s == 0)
		create_copy_map(parsing);
	else if (parsing->map.count_e == 0 && parsing->map.count_w == 0
		&& parsing->map.count_n == 0 && parsing->map.count_s == 1)
		create_copy_map(parsing);
	else if (parsing->map.count_e == 0 && parsing->map.count_w == 0
		&& parsing->map.count_n == 0 && parsing->map.count_s == 0)
		err_map("No player's position found in the map\n", parsing);
	else
		err_map("Too much player's position reference in the map\n", parsing);
}

void	check_player_character(t_utils_parsing *parsing)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (parsing->real_map[i])
	{
		j = 0;
		while (parsing->real_map[i][j])
		{
			if (parsing->real_map[i][j] == 'N')
				parsing->map.count_n++;
			else if (parsing->real_map[i][j] == 'S')
				parsing->map.count_s++;
			else if (parsing->real_map[i][j] == 'W')
				parsing->map.count_w++;
			else if (parsing->real_map[i][j] == 'E')
				parsing->map.count_e++;
			j++;
		}
		i++;
	}
	check_count(parsing);
}

void	find_player(t_utils_parsing *parsing)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (parsing->cpy_map[y])
	{
		x = 0;
		while (parsing->cpy_map[y][x])
		{
			if (parsing->cpy_map[y][x] == 'N' || parsing->cpy_map[y][x] == 'S'
				|| parsing->cpy_map[y][x] == 'W'
				|| parsing->cpy_map[y][x] == 'E')
			{
				parsing->map.p_y = y;
				parsing->map.p_x = x;
			}
			x++;
		}
		y++;
	}
}
