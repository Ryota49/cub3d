/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 23:52:50 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/07 16:41:23 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_utils_parsing *parsing, int y, int x)
{
	if (y < 0 || x < 0
		|| y >= parsing->height_map + 2
		|| x >= parsing->width_max + 2)
		return ;
	if (parsing->cpy_map[y][x] == '1' || parsing->cpy_map[y][x] == 'F')
		return ;
	if (parsing->cpy_map[y][x] == '0' || parsing->cpy_map[y][x] == 'N'
		|| parsing->cpy_map[y][x] == 'S' || parsing->cpy_map[y][x] == 'W'
		|| parsing->cpy_map[y][x] == 'E')
	{
		free_splitter(parsing->cpy_map);
		err_map("Error\nThe map is not surrounded by walls only\n", parsing);
	}
	parsing->cpy_map[y][x] = 'F';
	flood_fill(parsing, y + 1, x);
	flood_fill(parsing, y - 1, x);
	flood_fill(parsing, y, x + 1);
	flood_fill(parsing, y, x - 1);
}

void	flood_fill_player(t_utils_parsing *parsing, int y, int x)
{
	if (parsing->cpy_map[y][x] == '1' || parsing->cpy_map[y][x] == 'F')
		return ;
	if (parsing->cpy_map[y][x] == ' ' || parsing->cpy_map[y][x] == '\t')
	{
		free_splitter(parsing->cpy_map);
		err_map("Error\nEmpty area detected inside the map\n", parsing);
	}
	parsing->cpy_map[y][x] = 'F';
	flood_fill_player(parsing, y + 1, x);
	flood_fill_player(parsing, y - 1, x);
	flood_fill_player(parsing, y, x + 1);
	flood_fill_player(parsing, y, x - 1);
}
