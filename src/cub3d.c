/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/09 13:48:37 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_utils_parsing	pars;
	// t_game			g;
	// int				i;
	// int				j;

	if (argc != 2)
	{
		write (2, "Error\nWrong Number of argument\n", 31);
		return (1);
	}
	// ft_bzero(&g, sizeof(t_game));
	check_extension(argv[1]);
	initialise_parsing(&pars);
	open_file(&pars, argv[1]);
	if (init_game(&pars.game, &pars) == 0)
	{
		write(2, "Error\nFailed to initialize game or MLX", 39);
		return (1);
	}
	pars.game.pars = &pars;
	// i = 0;
	// while (pars.game.map[i])
	// {
	// 	j = 0;
	// 	while (pars.game.map[i][j])
	// 	{
	// 		printf("%c", pars.game.map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	
	// printf("MLX PTR: %p\n", pars.game.mlx);
	// printf("WIN PTR: %p\n", pars.game.win);
	mlx_add_loop_hook(pars.game.mlx, render, &pars.game);
	mlx_on_event(pars.game.mlx, pars.game.win, MLX_KEYDOWN, key_hook, &pars.game);
	// mlx_on_event(g.mlx, g.win, MLX_MOUSEDOWN, mouse_hook, g.mlx);
	mlx_on_event(pars.game.mlx, pars.game.win, MLX_WINDOW_EVENT, window_hook, &pars.game);
	mlx_loop(pars.game.mlx);
	// clean_game(&pars.game);
	clean_parsing(&pars);
	return (0);
}
