/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:11:02 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/26 20:18:15 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_new_line(char *path)
{
	size_t	i;

	i = 0;
	while (path[i] && path[i] != '\n')
		i++;
	if (path[i] == '\n')
		path[i] = '\0';
}

void    count_comma(t_utils_parsing *parsing)
{
    size_t  i;
    size_t  nbr_comma;

    i = 0;
    nbr_comma = 0;
    while (parsing->line[i])
    {
        if (parsing->line[i] == ',')
            nbr_comma++;
        i++;
    }
    if (nbr_comma != 2)
        err_free("Error\nBad structure of the color\n", parsing);
}
