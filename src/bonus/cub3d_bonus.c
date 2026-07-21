/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/21 12:38:42 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_utils_parsing	p;

	if (argc != 2)
		write(2, "Error\nWrong Number of argument\n", 31);
	if (argc != 2)
		return (1);
	check_extension(argv[1]);
	initialise_parsing(&p);
	open_file(&p, argv[1]);
	if (init_game(&p.game, &p) == 0)
	{
		write(2, "Error\nFailed to initialize game or MLX", 39);
		return (1);
	}
	p.game.pars = &p;
	mlx_add_loop_hook(p.game.mlx, render, &p.game);
	mlx_on_event(
		p.game.mlx, p.game.win, MLX_KEYDOWN, key_down_hook, &p.game);
	mlx_on_event(
		p.game.mlx, p.game.win, MLX_KEYUP, key_up_hook, &p.game);
	mlx_on_event(
		p.game.mlx, p.game.win, MLX_WINDOW_EVENT, window_hook, &p.game);
	mlx_loop(p.game.mlx);
	clean_parsing(&p);
	return (0);
}
