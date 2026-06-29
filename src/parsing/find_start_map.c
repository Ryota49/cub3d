/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 18:30:10 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/29 18:39:03 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// apres qu'on a nos 4 textures et 2 couleurs de stocker,
	// on considere que toutes les prochaines lignes sont des
	// lignes vides  ou avec uniquement \n donc pas de debut de map
	// et si on y trouve une ligne avec un 1, 0, N, S, W ou E + espace ou tab potentiel
	// alors la map est considerer commencer

int    check_characters_line(t_utils_parsing *parsing)
{
    size_t  i;

    i = 0;
    remove_new_line(parsing->line);
    while (parsing->line[i])
    {
        if (ft_strchr("10NSWE", parsing->line[i]))
            return (1);
        if (parsing->line[i] != ' ' && parsing->line[i] != '\t')
            err_free("Error\nUnknown character below the header\n", parsing);
        i++;
    }
    return (0);
}

void    start_map(t_utils_parsing *parsing)
{
    printf("fonction start map\n %s\n", parsing->line);
    
}

void    find_start_map(t_utils_parsing *parsing)
{
    parsing->splitter = NULL;
    parsing->line = get_next_line(parsing->fd);
    while (parsing->line != NULL)
    {
        if (check_characters_line(parsing) == 1)
        {
            printf("JE SUIS LA PREMIERE LIGNE DE LA MAP\n");
            parsing->start_map = 1;
            break ;
        }
        else if (check_characters_line(parsing) == 0)
            parsing->start_map = 0;
        free(parsing->line);
        parsing->line = get_next_line(parsing->fd);
    }
    if (parsing->start_map == 1)
        start_map(parsing);
    else
        err_free("Error\nNo map found\n", parsing);
}
