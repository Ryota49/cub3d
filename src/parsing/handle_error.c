/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/24 19:56:41 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_free(char *msg, t_utils_parsing *parsing)
{
	free_splitter(parsing->splitter);
	if (parsing->line != NULL)
	{
		free(parsing->line);
		get_next_line(-1);
	}
	close (parsing->fd);
	if (parsing->game.texture_n)
		free (parsing->game.texture_n);
	if (parsing->game.texture_s)
		free (parsing->game.texture_s);
	if (parsing->game.texture_w)
		free(parsing->game.texture_w);
	if (parsing->game.texture_e)
		free (parsing->game.texture_e);
	write (2, msg, ft_strlen(msg));
	exit (1);
}

void	handle_error(char *msg_error)
{
	write (2, msg_error, ft_strlen(msg_error));
	exit (1);
}
