/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/21 12:38:14 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_splitter(char **splitter)
{
	size_t	i;

	i = 0;
	while (splitter[i])
	{
		free (splitter[i]);
		i++;
	}
	free (splitter);
}
