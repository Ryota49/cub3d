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

void    check_value_range(t_utils_parsing *parsing, char **values, size_t i)
{
    if (ft_atoi(values[i]) >= 0 && ft_atoi(values[i]) <= 255)
    {
        if (parsing->game.boolean == 1)
        {
            if (i == 0)
                parsing->game.floor.r = ft_atoi(values[i]);
            else if (i == 1)
                parsing->game.floor.g = ft_atoi(values[i]);
            else if (i == 2)
                parsing->game.floor.b = ft_atoi(values[i]);
        }
        if (parsing->game.boolean == 2)
        {
            if (i == 0)
                parsing->game.ceiling.r = ft_atoi(values[i]);
            else if (i == 1)
                parsing->game.ceiling.g = ft_atoi(values[i]);
            else if (i == 2)
                parsing->game.ceiling.b = ft_atoi(values[i]);
        }
    }
    else
        err_values("Error\nValue of colors must be between 0 and 255\n", parsing, values);
}

void    check_each_character(t_utils_parsing *parsing, char **values, size_t i)
{
    size_t  j;

    j = 0;
    while (values[i][j])
    {
        if (values[i][j] >= '0' && values[i][j] <= '9')
            j++;
        else
            err_values("Error\nUnknown character in color pattern\n", parsing, values);
    }
    check_value_range(parsing, values, i);
}

void    split_values(t_utils_parsing *parsing)
{
    char    **values;
    size_t  i;

    i = 0;
    values = ft_split_tab(parsing->splitter[1], ",\t ");
    if (!values[0] || !values[1] || !values[2])
        err_values("Error\nMissing value for color\n", parsing, values);
    if (values[3] != NULL)
        err_values("Error\nToo much values for the color\n", parsing, values);
    while (values[i])
    {
        if (ft_strlen(values[i]) <= 3)
            check_each_character(parsing, values, i);
        else
            err_values("Error\nWrong len for colors (max of 3)\n", parsing, values);
        i++;
    }
    free_splitter(values);
}

void	check_color_f(t_utils_parsing *parsing)
{
	if (parsing->splitter[2] != NULL)
		err_free("Error\nMultiple token in line\n", parsing);
    if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo color detected for the floor\n", parsing);
    remove_new_line(parsing->splitter[1]);
    count_comma(parsing);
    parsing->game.boolean = 1;
    split_values(parsing);
	parsing->count_f++;
    if (parsing->count_f > 1)
        err_free("Error\nToo much floor reference\n", parsing);
    printf("valeur du floor:\nR:%d\nG:%d\nB:%d\n", parsing->game.floor.r, parsing->game.floor.g, parsing->game.floor.b);;
}

void	check_color_c(t_utils_parsing *parsing)
{
	if (parsing->splitter[2] != NULL)
		err_free("Error\nMultiple token in line\n", parsing);
    if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo color detected for the ceiling\n", parsing);
    remove_new_line(parsing->splitter[1]);
    count_comma(parsing);
    parsing->game.boolean = 2;
    split_values(parsing);
	parsing->count_c++;
    if (parsing->count_f > 1)
        err_free("Error\nToo much ceiling reference\n", parsing);
    printf("valeur du ceiling:\nR:%d\nG:%d\nB:%d\n", parsing->game.ceiling.r, parsing->game.ceiling.g, parsing->game.ceiling.b);
}
