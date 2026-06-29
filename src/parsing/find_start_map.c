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

//parcourir tout le fichier jusqu'au bout de la map, pour connaitre la taille de la map
//pour pouvoir allouer a la bonne taille apres dans notre structure chaque ligne puis
// faire des ft_strdup de chacune des lignes en relisant a nouveau le fichier a partir de
// line_read du coup

void     check_after_map(t_utils_parsing *parsing)
{
    size_t  i;

    while (parsing->line != NULL)
    {
        i = 0;
        remove_new_line(parsing->line);
        while (parsing->line[i])
        {
            if (parsing->line[i] != ' ' && parsing->line[i] != '\t')
                err_free("Error\nEmpty line in the map\n", parsing);
            i++;
        }
        free(parsing->line);
        parsing->line = get_next_line(parsing->fd);
    }
}

void    start_map(t_utils_parsing *parsing)
{
    size_t  i;
    int  only_space;

    while (parsing->line != NULL)
    {
        remove_new_line(parsing->line);
        only_space = 0;
        i = 0;
        while (parsing->line[i])
        {
            if (ft_strchr("10NSWE", parsing->line[i]))
                only_space-- ;
            else if (parsing->line[i] == ' ' || parsing->line[i] == '\t')
                only_space++ ;
            else if (!ft_strchr("10NSWE \t", parsing->line[i]))
                err_free("Error\nUnknown character in the map\n", parsing);
            i++;
        }
        if ((size_t)only_space == ft_strlen(parsing->line))
        {
            check_after_map(parsing);
            break ;
        }
        parsing->height_map++;
        free(parsing->line);
        parsing->line = get_next_line(parsing->fd);
    }
}

void    find_start_map(t_utils_parsing *parsing)
{
    parsing->splitter = NULL;
    parsing->line = get_next_line(parsing->fd);
    while (parsing->line != NULL)
    {
        parsing->line_read++;
        if (check_characters_line(parsing) == 1)
        {
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
