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

void    check_value_range(t_utils_parsing *parsing, size_t i)
{
    if (ft_atoi(parsing->splitter[i]) >= 0 && ft_atoi(parsing->splitter[i]) <= 255)
    {
        if (parsing->game.boolean == 1)
        {
            if (i == 1)
                parsing->game.floor.r = ft_atoi(parsing->splitter[i]);
            else if (i == 2)
                parsing->game.floor.g = ft_atoi(parsing->splitter[i]);
            else if (i == 3)
                parsing->game.floor.b = ft_atoi(parsing->splitter[i]);
        }
        if (parsing->game.boolean == 2)
        {
            if (i == 1)
                parsing->game.ceiling.r = ft_atoi(parsing->splitter[i]);
            else if (i == 2)
                parsing->game.ceiling.g = ft_atoi(parsing->splitter[i]);
            else if (i == 3)
                parsing->game.ceiling.b = ft_atoi(parsing->splitter[i]);
        }
    }
    else
        err_free("Error\nValue of colors must be between 0 and 255\n", parsing);
}

void    check_each_character(t_utils_parsing *parsing, size_t i)
{
    size_t  j;

    j = 0;
    while (parsing->splitter[i][j])
    {
        if (parsing->splitter[i][j] >= '0' && parsing->splitter[i][j] <= '9')
            j++;
        else
            err_free("Error\nUnknown character in color pattern\n", parsing);
    }
    check_value_range(parsing, i);
}

void    split_values(t_utils_parsing *parsing)
{
    size_t  i;

    i = 1;
    if (!parsing->splitter[1] || !parsing->splitter[2] || !parsing->splitter[3])
        err_free("Error\nMissing value for color\n", parsing);
    if (parsing->splitter[1][0] == '\0' || parsing->splitter[2][0] == '\0' || parsing->splitter[3][0] == '\0')
        err_free("Error\nEmpty value for color\n", parsing);
    if (parsing->splitter[4] != NULL)
        err_free("Error\nToo much values for the color\n", parsing);
    while (parsing->splitter[i])
    {
        if (ft_strlen(parsing->splitter[i]) <= 3)
            check_each_character(parsing, i);
        else
            err_free("Error\nWrong len for colors (max of 3)\n", parsing);
        i++;
    }
}

void	check_color_f(t_utils_parsing *parsing)
{
    int i = 1;

    if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo color detected for the floor\n", parsing);
    if (parsing->splitter[1][0] == ',')
        err_free("Error\nCommas must be between numbers, not at the start\n", parsing);
    count_comma(parsing);
    free_splitter(parsing->splitter);
    parsing->splitter = ft_split_tab(parsing->line, ",\t ");
    while (parsing->splitter[i])
    {
        remove_new_line(parsing->splitter[i]);
        i++;
    }
    parsing->game.boolean = 1;
    split_values(parsing);
	parsing->count_f++;
    if (parsing->count_f > 1)
        err_free("Error\nToo much floor reference\n", parsing);
}

void	check_color_c(t_utils_parsing *parsing)
{
	int i = 1;

    if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo color detected for the floor\n", parsing);
    if (parsing->splitter[1][0] == ',')
        err_free("Error\nCommas must be between numbers, not at the start\n", parsing);
    count_comma(parsing);
    free_splitter(parsing->splitter);
    parsing->splitter = ft_split_tab(parsing->line, ",\t ");
    while (parsing->splitter[i])
    {
        remove_new_line(parsing->splitter[i]);
        i++;
    }
    parsing->game.boolean = 2;
    split_values(parsing);
	parsing->count_c++;
    if (parsing->count_c > 1)
        err_free("Error\nToo much floor reference\n", parsing);
}
