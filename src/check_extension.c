/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/24 12:29:49 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_nbr_dot(char *map_file)
{
	int	nbr_dot;
	int	i;

	nbr_dot = 0;
	i = 0;
	while (map_file[i])
	{
		if (map_file[i] == '.')
			nbr_dot++;
		i++;
	}
	return (nbr_dot);
}

void	check_extension_after_dot(char *map_file, int i)
{
	if (map_file[i + 1] == 'c' && map_file[i + 2] == 'u'
		&& map_file[i + 3] == 'b' && map_file[i + 4] == '\0')
		return ;
	else
	{
		write (2, "Error: Wrong extension name of the file\n", 40);
		exit (2);
	}
}

void	check_extension(char *map_file)
{
	int	i;

	i = 0;
	if (check_nbr_dot(map_file) > 1)
	{
		write (2, "Error: Wrong number of dot in the file\n", 39);
		exit (2);
	}
	while (map_file[i] && map_file[i] != '.')
		i++;
	if (map_file[i] == '\0')
	{
		write (2, "Error: No extension of the file detected\n", 41);
		exit (2);
	}
	else if (map_file[i] == '.')
		check_extension_after_dot(map_file, i);
}
