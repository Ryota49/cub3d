/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:15:07 by byonis            #+#    #+#             */
/*   Updated: 2026/06/29 12:50:46 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_plane(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	if (c == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	if (c == 'E')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;	
	}
	if (c == 'W')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
}

void	player_dir(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
	}
	if (c == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
	}
	if (c == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;	
	}
	if (c == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
	}
}

void	player_pos(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	if (!game || !game->map)
		return ;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'E')
			{
				c = game->map[y][x];
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				player_dir(game, c);
				player_plane(game, c);
			}
			x++;
		}
		y++;
	}
}
