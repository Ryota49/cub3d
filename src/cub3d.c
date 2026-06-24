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

void	open_file(char *map_file)
{
	int	fd;
	char	*line;
	int	i;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_error("Error: Map file cannot be open (probably doesn't exist)\n");
	line = get_next_line(fd);
	if (line == NULL)
		handle_error("Error: Map file is empty, nothing inside of it\n");
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0')
		{
			while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
				i++;
			if (line[i] == 'N' && line[i + 1] == 'O')
				;// check if it's line of north with texture
			else if (line[i] == 'S' && line[i + 1] == 'O')
				;// check if it's line of south with texture
			else if (line[i] == 'W' && line[i + 1] == 'E')
				;// check if it's line of west with texture
			else if (line[i] == 'E' && line[i + 1] == 'A')
				;// check if it's line of west with texture
		}
		line = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write (2, "Error: Wrong Number of argument\n", 32);
		return (2);
	}
	check_extension(argv[1]);
	open_file(argv[1]);
	return (0);
}
