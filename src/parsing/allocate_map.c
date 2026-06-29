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

/*void    check_player_character(t_utils_parsing *parsing, char *map_file)
{

}*/

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
        printf("ma map dans ma struct:\n%s\n", parsing->real_map[i]);
        free (parsing->line);
        i++;
    }
    parsing->real_map[i] = NULL;
    //check_player_character(parsing, map_file);
}
