/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header_of_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/24 20:15:12 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// demain rajouter la verif que le fichier de la texture existe bien dans 
// splitter[1] pour chaque ligne du header

void	handle_splitter_two(char **splitter, t_utils_parsing *parsing, char *line, int fd)
{
	if (ft_strcmp(splitter[0], "EA") == 0)
	{
		if (splitter[2] != NULL)
			handle_error_and_free("Error\nUnknown or multiple token in line\n", splitter, line, fd);
		parsing->count_ea++;
	}
	else if (ft_strcmp(splitter[0], "F") == 0)
	{
		if (splitter[2] != NULL)
			handle_error_and_free("Error\nUnknown or multiple token in line\n", splitter, line, fd);
		parsing->count_f++;
	}
	else if (ft_strcmp(splitter[0], "C") == 0)
	{
		if (splitter[2] != NULL)
			handle_error_and_free("Error\nUnknown or multiple token in line\n", splitter, line, fd);
		parsing->count_c++;
	}
	else
		handle_error_and_free("Error\nUnknown or multiple token in line\n", splitter, line, fd);
}

void	handle_splitter(char **splitter, t_utils_parsing *parsing, char *line, int fd)
{
	if (ft_strcmp(splitter[0], "NO") == 0)
	{
		if (splitter[2] != NULL)
			handle_error_and_free("Error\nUnknown or multiple token in line\n", splitter, line, fd);
		parsing->count_no++;
	}
	else if (ft_strcmp(splitter[0], "SO") == 0)
	{
		if (splitter[2] != NULL)
			handle_error_and_free("Error\nUnknown or multiple token in line\n", splitter, line, fd);
		parsing->count_so++;
	}
	else if (ft_strcmp(splitter[0], "WE") == 0)
	{
		if (splitter[2] != NULL)
			handle_error_and_free("Error\nUnknown or multiple token in line\n", splitter, line, fd);
		parsing->count_we++;
	}
	else
		handle_splitter_two(splitter, parsing, line, fd);
}

// Une fois qu'on a nos 6 valeurs comme il faut + save les chemins de splitter[1] en gros, on utilise plus jamais
// splitter et on fait la suite ligne par ligne en utilisant line, pour partir du principe que l'on commence
// a etre dans la map et parser la map, si la ligne est entierement vide = espace avant la map, si la ligne il y a 
// soit 0, soit 1, soit W, soit S, soit W, soit E, soit un espace, alors la ligne est valide et la map vient de commencer.
// Si jamais on a detecter un autre caractere dans la ligne ou les lignes suivantes, alors la map est invalide.
// egalement si la derniere ligne est remplis de 1 ou d'espace et que le line d'apres vaut NULL, alors on est a la fin.
// demain continuer la suite juste apres le while (line != NULL) ci dessous (effacer le 2eme while de la fonction
// qui servait juste a eviter d'avoir le leak de gnl car on etait pas au bout du fichier ouvert).

void	manage_line(t_utils_parsing *parsing, char *line, int fd)
{
	char	**splitter;

	while (line != NULL)
	{
		splitter = ft_split(line, ' ');
		if (splitter[0] != NULL)
			handle_splitter(splitter, parsing, line, fd);
		free_splitter(splitter);
		if (parsing->count_no == 1 && parsing->count_so == 1 && parsing->count_we == 1 && parsing->count_ea == 1
			&& parsing->count_f == 1 && parsing->count_c == 1)
            {
                parsing->header_done = 1;
                break ;
            }
        free (line);
		line = get_next_line(fd);
	}
	while (line != NULL && parsing->header_done == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	open_file(t_utils_parsing *parsing, char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		handle_error("Error\nMap file cannot be open (probably doesn't exist)\n");
	line = get_next_line(fd);
	if (line == NULL)
		handle_error("Error\nMap file is empty, nothing inside of it\n");
	manage_line(parsing, line, fd);
	if (parsing->count_no != 1 || parsing->count_so != 1 || parsing->count_we != 1 || parsing->count_ea != 1
		|| parsing->count_f != 1 || parsing->count_c != 1)
		handle_error("Error\nwrong number of token NO, SO, WE, EA, F or C\n");
	if (parsing->count_no == 1 && parsing->count_so == 1 && parsing->count_we == 1 && parsing->count_ea == 1
		&& parsing->count_f == 1 && parsing->count_c == 1)
		write (1, "good count of NO, SO, WE, EA, F and C in the file\n", 50);
	close (fd);
}
