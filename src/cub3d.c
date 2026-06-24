/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/23 16:52:49 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 1. Essayer d'ouvrir le fichier avec open, lire son contenu ligne par ligne
// 2. Recuperer les informations importantes et les stocker dans une structure
// 3. verifier que la map est valide (joueur entourer de mur)

int	main(int argc, char **argv)
{
	t_utils_parsing	parsing;

	if (argc != 2)
	{
		write (2, "Error\n Wrong Number of argument\n", 32);
		return (2);
	}
	check_extension(argv[1]);
	initialise_parsing(&parsing);
	open_file(&parsing, argv[1]);
	return (0);
}
