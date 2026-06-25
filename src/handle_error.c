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

#include <cub3d.h>

void	handle_error_and_free(char *msg, char **splitter, char *line, int fd)
{
	size_t	i;

	i = 0;
	while (splitter[i])
	{
		free(splitter[i]);
		i++;
	}
	free (splitter);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	write (2, msg, ft_strlen(msg));
	exit (2);
}

void	handle_error(char *msg_error)
{
	write (2, msg_error, ft_strlen(msg_error));
	exit (2);
}
