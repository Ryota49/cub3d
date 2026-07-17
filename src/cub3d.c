/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/15 13:53:40 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_utils_parsing	pars;

	if (argc != 2)
	{
		write (2, "Error\nWrong Number of argument\n", 31);
		return (1);
	}
	check_extension(argv[1]);
	initialise_parsing(&pars);
	open_file(&pars, argv[1]);
	if (init_game(&pars.game, &pars) == 0)
	{
		write(2, "Error\nFailed to initialize game or MLX", 39);
		return (1);
	}
	pars.game.pars = &pars;
	
	mlx_add_loop_hook(pars.game.mlx, render, &pars.game);
	mlx_on_event(pars.game.mlx, pars.game.win, MLX_KEYDOWN, key_down_hook, &pars.game);
	mlx_on_event(pars.game.mlx, pars.game.win, MLX_KEYUP, key_up_hook, &pars.game);
	// mlx_on_event(g.mlx, g.win, MLX_MOUSEDOWN, mouse_hook, g.mlx);
	mlx_on_event(pars.game.mlx, pars.game.win, MLX_WINDOW_EVENT, window_hook, &pars.game);
	mlx_loop(pars.game.mlx);
	clean_parsing(&pars);
	return (0);
}
