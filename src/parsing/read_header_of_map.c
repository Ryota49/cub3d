/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header_of_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/26 18:12:03 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// demain rajouter la verif que le fichier de la texture existe bien dans 
// splitter[1] pour chaque ligne du header

void	handle_splitter(t_utils_parsing *parsing)
{
	if (ft_strcmp(parsing->splitter[0], "NO") == 0)
		check_path_texture_no(parsing);
	else if (ft_strcmp(parsing->splitter[0], "SO") == 0)
		check_path_texture_so(parsing);
	else if (ft_strcmp(parsing->splitter[0], "WE") == 0)
		check_path_texture_we(parsing);
	else if (ft_strcmp(parsing->splitter[0], "EA") == 0)
		check_path_texture_ea(parsing);
	else if (ft_strcmp(parsing->splitter[0], "F") == 0)
		check_color_f(parsing);
	else if (ft_strcmp(parsing->splitter[0], "C") == 0)
		check_color_c(parsing);
	else
		err_free("Error\nUnknown token in header line\n", parsing);
}

// Parser R G B (les couleurs) que ca soit bien entre 0 et 255 
// avec 3 values max et min, si c'est good on stock 
// R = 1st value, G = 2eme value, B = 3eme value dans 3 int
// donc int r, int g, int b dans une structure.
// Une fois qu'on a nos 6 valeurs comme il faut + 
// save les chemins de splitter[1] en gros, on utilise plus jamais
// splitter et on fait la suite ligne par ligne en utilisant line
// pour partir du principe que l'on commence
// a etre dans la map et parser la map, si la ligne est entierement
// vide = espace vide avant la map, si la ligne il y a 
// soit 0, soit 1, soit W, soit S, soit W, soit E, avec
// possibilite d'espace en plus, 
// alors la ligne est valide et la map vient de commencer.
// Si jamais on a detecter un autre caractere dans la ligne 
// ou les lignes suivantes, alors la map est invalide.
// egalement si la derniere ligne est remplis de 1 ou d'espace
// et que le line d'apres vaut NULL, alors on est a la fin.
// demain continuer la suite juste apres le while (line != NULL)
// ci dessous (effacer le 2eme while de la fonction
// qui servait juste a eviter d'avoir le leak de gnl
//car on etait pas au bout du fichier ouvert).

void	manage_line(t_utils_parsing *parsing)
{
	while (parsing->line != NULL)
	{
		parsing->splitter = ft_split(parsing->line, ' ');
		if (parsing->splitter[0] != NULL && parsing->splitter[0][0] != '\n')
			handle_splitter(parsing);
		free_splitter(parsing->splitter);
		if (parsing->count_no == 1 && parsing->count_so == 1
			&& parsing->count_we == 1 && parsing->count_ea == 1
			&& parsing->count_f == 1 && parsing->count_c == 1)
		{
			parsing->header_done = 1;
			break ;
		}
		free (parsing->line);
		parsing->line = get_next_line(parsing->fd);
	}
	// apres qu'on a nos 4 textures et 2 couleurs de stocker,
	// on considere que toutes les prochaines lignes sont des
	// lignes vides  ou avec uniquement \n donc pas de debut de map
	// et si on y trouve une ligne avec un 1, 0, N, S, W ou E + espace ou tab potentiel
	// alors la map est considerer commencer
	if (parsing->header_done == 1)
	{
		free (parsing->line);
		get_next_line(-1);
	}
}

void	open_file(t_utils_parsing *parsing, char *map_file)
{
	parsing->fd = open(map_file, O_RDONLY);
	if (parsing->fd < 0)
		handle_error("Error\nMap file cannot be open\n");
	parsing->line = get_next_line(parsing->fd);
	if (parsing->line == NULL)
		handle_error("Error\nMap file is empty, nothing inside\n");
	manage_line(parsing);
	if (parsing->header_done == 0)
		err_free("Error\nWrong number of tokens in map file\n", parsing);
	if (parsing->header_done == 1)
		write (1, "Good count of NO, SO, WE, EA, F and C in the file\n", 50);
	close (parsing->fd);
}
