/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/26 16:04:36 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// prochainement accepter egalement les fichier .jpg ou autres que la macrolibX peut lire 
// faire une fonction a part qui s'occupe de check toutes les differences extensions

void	check_path_texture_no(t_utils_parsing *parsing)
{
	int	fd_texture;
	int	len_path;

	if (parsing->splitter[2] != NULL)
		err_free("Error\nMultiple token in line NO\n", parsing);
	if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo path detected for NO texture\n", parsing);
	remove_new_line(parsing->splitter[1]);
	if (parsing->splitter[1])
	{
		fd_texture = open(parsing->splitter[1], O_RDONLY);
		if (fd_texture < 0)
			err_free("Error\nCannot open file texture for NO\n", parsing);
		close (fd_texture);
		len_path = ft_strlen(parsing->splitter[1]);
		if (parsing->splitter[1][len_path - 1] != 'm'
			|| parsing->splitter[1][len_path - 2] != 'p'
			|| parsing->splitter[1][len_path - 3] != 'x'
			|| parsing->splitter[1][len_path - 4] != '.')
			err_free("Error\nWrong file extension for NO texture\n", parsing);
		parsing->count_no++;
		if (parsing->count_no > 1)
			err_free("Error\nToo much NO reference\n", parsing);
		parsing->game.texture_n = ft_strdup(parsing->splitter[1]);
	}
}

void	check_path_texture_so(t_utils_parsing *parsing)
{
	int	fd_texture;
	int	len_path;

	if (parsing->splitter[2] != NULL)
		err_free("Error\nMultiple token in line SO\n", parsing);
	if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo path detected for SO texture\n", parsing);
	remove_new_line(parsing->splitter[1]);
	if (parsing->splitter[1])
	{
		fd_texture = open(parsing->splitter[1], O_RDONLY);
		if (fd_texture < 0)
			err_free("Error\nCannot open file texture for SO\n", parsing);
		close (fd_texture);
		len_path = ft_strlen(parsing->splitter[1]);
		if (parsing->splitter[1][len_path - 1] != 'm'
			|| parsing->splitter[1][len_path - 2] != 'p'
			|| parsing->splitter[1][len_path - 3] != 'x'
			|| parsing->splitter[1][len_path - 4] != '.')
			err_free("Error\nWrong file extension for SO texture\n", parsing);
		parsing->count_so++;
		if (parsing->count_so > 1)
			err_free("Error\nToo much SO reference\n", parsing);
		parsing->game.texture_s = ft_strdup(parsing->splitter[1]);
	}
}

void	check_path_texture_we(t_utils_parsing *parsing)
{
	int	fd_texture;
	int	len_path;

	if (parsing->splitter[2] != NULL)
		err_free("Error\nMultiple token in line WE\n", parsing);
	if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo path detected for WE texture\n", parsing);
	remove_new_line(parsing->splitter[1]);
	if (parsing->splitter[1])
	{
		fd_texture = open(parsing->splitter[1], O_RDONLY);
		if (fd_texture < 0)
			err_free("Error\nCannot open file texture for WE\n", parsing);
		close (fd_texture);
		len_path = ft_strlen(parsing->splitter[1]);
		if (parsing->splitter[1][len_path - 1] != 'm'
			|| parsing->splitter[1][len_path - 2] != 'p'
			|| parsing->splitter[1][len_path - 3] != 'x'
			|| parsing->splitter[1][len_path - 4] != '.')
			err_free("Error\nWrong file extension for WE texture\n", parsing);
		parsing->count_we++;
		if (parsing->count_we > 1)
			err_free("Error\nToo much WE reference\n", parsing);
		parsing->game.texture_w = ft_strdup(parsing->splitter[1]);
	}
}

void	check_path_texture_ea(t_utils_parsing *parsing)
{
	int	fd_texture;
	int	len_path;

	if (parsing->splitter[2] != NULL)
		err_free("Error\nMultiple token in line EA\n", parsing);
	if (!parsing->splitter[1] || parsing->splitter[1][0] == '\0')
		err_free("Error\nNo path detected for EA texture\n", parsing);
	remove_new_line(parsing->splitter[1]);
	if (parsing->splitter[1])
	{
		fd_texture = open(parsing->splitter[1], O_RDONLY);
		if (fd_texture < 0)
			err_free("Error\nCannot open file texture for EA\n", parsing);
		close (fd_texture);
		len_path = ft_strlen(parsing->splitter[1]);
		if (parsing->splitter[1][len_path - 1] != 'm'
			|| parsing->splitter[1][len_path - 2] != 'p'
			|| parsing->splitter[1][len_path - 3] != 'x'
			|| parsing->splitter[1][len_path - 4] != '.')
			err_free("Error\nWrong file extension for EA texture\n", parsing);
		parsing->count_ea++;
		if (parsing->count_ea > 1)
			err_free("Error\nToo much EA reference\n", parsing);
		parsing->game.texture_e = ft_strdup(parsing->splitter[1]);
	}
}
