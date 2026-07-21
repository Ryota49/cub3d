/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 23:52:50 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/07 16:07:20 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first_last_line(t_utils_parsing *parsing, size_t *i)
{
	int	j;

	j = 0;
	parsing->cpy_map[*i] = malloc(sizeof(char) * (parsing->width_max + 3));
	while (j < parsing->width_max + 2)
	{
		parsing->cpy_map[*i][j] = 'P';
		j++;
	}
	parsing->cpy_map[*i][j] = '\0';
	(*i)++;
}

void	fill_with_p(t_utils_parsing *parsing, size_t i, size_t *j)
{
	(*j)++;
	while (*j < (size_t)parsing->width_max + 2)
	{
		parsing->cpy_map[i][*j] = 'P';
		(*j)++;
	}
}

void	fill_copy_map(t_utils_parsing *parsing, size_t i, size_t h)
{
	size_t	j;
	size_t	k;

	while (parsing->real_map[h])
	{
		if (i == 0)
			first_last_line(parsing, &i);
		j = 0;
		k = 0;
		parsing->cpy_map[i] = malloc(sizeof(char) * (parsing->width_max + 3));
		parsing->cpy_map[i][j] = 'P';
		while (parsing->real_map[h][k])
		{
			j++;
			parsing->cpy_map[i][j] = parsing->real_map[h][k];
			k++;
		}
		fill_with_p(parsing, i, &j);
		parsing->cpy_map[i][j] = '\0';
		h++;
		i++;
	}
	first_last_line(parsing, &i);
	parsing->cpy_map[i] = NULL;
}

void	create_copy_map(t_utils_parsing *parsing)
{
	size_t	i;
	size_t	h;

	i = 0;
	h = 0;
	parsing->cpy_map = malloc(sizeof(char *) * (parsing->height_map + 3));
	find_longest_line(parsing);
	fill_copy_map(parsing, i, h);
	flood_fill(parsing, 0, 0);
	find_player(parsing);
	flood_fill_player(parsing, parsing->map.p_y, parsing->map.p_x);
	free_splitter(parsing->cpy_map);
	parsing->cpy_map = NULL;
	parsing->game.map = parsing->real_map;
}

void	allocate_map(t_utils_parsing *parsing, char *map_file)
{
	int	i;

	i = 0;
	parsing->real_map = malloc(sizeof(char *) * (parsing->height_map + 1));
	parsing->fd = open(map_file, O_RDONLY);
	while (i < parsing->line_read - 1)
	{
		parsing->line = get_next_line(parsing->fd);
		free (parsing->line);
		parsing->line_read--;
	}
	while (i < parsing->height_map)
	{
		parsing->line = get_next_line(parsing->fd);
		remove_new_line(parsing->line);
		parsing->real_map[i] = ft_strdup(parsing->line);
		free (parsing->line);
		i++;
	}
	parsing->real_map[i] = NULL;
	parsing->line = NULL;
	close (parsing->fd);
	check_player_character(parsing);
}
