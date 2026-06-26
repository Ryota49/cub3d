/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/26 10:31:04 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 1. Essayer d'ouvrir le fichier avec open, lire son contenu ligne par ligne
// 2. Recuperer les informations importantes et les stocker dans une structure
// 3. verifier que la map est valide (joueur entourer de mur)

int	main(int argc, char **argv)
{
	t_game			g;
	// t_utils_parsing	parsing;

	if (argc != 2)
	{
		write (2, "Error\n Wrong Number of argument\n", 32);
		return (2);
	}
	(void)argv;
	ft_bzero(&g, sizeof(t_game));
	// check_extension(argv[1]);
	// initialise_parsing(&parsing);
	// open_file(&parsing, argv[1]);
	init_game(&g);
	mlx_on_event(g.mlx, g.win, MLX_KEYDOWN, key_hook, g.mlx);
	// mlx_on_event(g.mlx, g.win, MLX_MOUSEDOWN, mouse_hook, g.mlx);
	mlx_on_event(g.mlx, g.win, MLX_WINDOW_EVENT, window_hook, g.mlx);
	mlx_loop(g.mlx);
	clean(&g);
	return (0);
}
