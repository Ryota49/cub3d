/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 23:52:50 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/29 23:54:42 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Une fois que tout est dans ma struct,
// on va check si on a au moins un N,S,W,E character
// dans la map et si y'en a pas plusieurs ou + de 1 du meme type

void    first_last_line(t_utils_parsing *parsing, size_t *i)
{
    int  j;

    j = 0;
    parsing->cpy_map[*i] = malloc(sizeof(char) * (parsing->width_max + 2));
    while (j < parsing->width_max + 2)
    {
        parsing->cpy_map[*i][j] = 'P';
        j++;
    }
    parsing->cpy_map[*i][j] = '\0';
    (*i)++;
}

void    create_copy_map(t_utils_parsing *parsing)
{
    size_t  i;
    size_t  j;
    size_t  k;
    size_t  h;

    i = 0;
    h = 0;
    parsing->cpy_map = malloc(sizeof(char *) * (parsing->height_map + 3));
    find_longest_line(parsing);
    while (parsing->real_map[h])
    {
        if (i == 0)
            first_last_line(parsing, &i);
        j = 0;
        k = 0;
        parsing->cpy_map[i] = malloc(sizeof(char) * (parsing->width_max + 2));
        parsing->cpy_map[i][j] = 'P';
        while (parsing->real_map[h][k])
        {
            j++;
            parsing->cpy_map[i][j] = parsing->real_map[h][k];
            k++;
        }
        j++;
        while (j < (size_t)parsing->width_max + 2)
        {
            parsing->cpy_map[i][j] = 'P';
            j++;
        }
        parsing->cpy_map[i][j] = '\0';
        h++;
        i++;
    }
    first_last_line(parsing, &i);
    parsing->cpy_map[i] = NULL;
    i = 0;
    printf("copy of my map for fill flood from outside:\n");
    while (parsing->cpy_map[i])
    {
        printf("%s\n", parsing->cpy_map[i]);
        i++;
    }
}

// demain commencer le flood_fill depuis 0,0 de la cpy_map sur P,
// suivre tous les P, detecter les 0 et voir
// si y'en a qui est coller a un P ou a du vide, si c'est le cas alors map invalide
// tant que tous les 0 ou position du joueur sont entourer de 0 ou de 1 alors map jouable.

void    check_count(t_utils_parsing *parsing)
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

void    check_player_character(t_utils_parsing *parsing)
{
    size_t  i;
    size_t  j;

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

void    allocate_map(t_utils_parsing *parsing, char *map_file)
{
    int  i;

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
    close (parsing->fd);
    check_player_character(parsing);
}
