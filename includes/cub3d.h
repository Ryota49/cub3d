/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/24 20:10:20 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../MacroLibX-master/includes/mlx.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct s_utils_parsing
{
	int	count_no;
	int	count_so;
	int	count_we;
	int	count_ea;
	int	count_f;
	int	count_c;
	int	header_done;
	int	start_map;

}	t_utils_parsing;

typedef struct s_game
{
	char	**map;
	char	*texture_n;
	char	*texture_s;
	char	*texture_e;
	char	*texture_w;

	void	*mlx;
	void	*win;

	float	pos_x;
	float	pos_y;

	float	dir_x;
	float	dir_y;

	float	plane_x;
	float	plane_y;

	int		screen_w;
	int		screen_h;
}	t_game;

// macrolibx functions 
void	clean(t_game *g);

// extension parsing
void	check_extension(char *map_file);

// open map_file and read line by line the header for now
void	open_file(t_utils_parsing *parsing, char *map_file);

// free functions
void	free_splitter(char **splitter);

// handle error
void	handle_error(char *msg_error);
void	handle_error_and_free(char *msg, char **splitter, char *line, int fd);

// initialise structure
void	initialise_parsing(t_utils_parsing *parsing);

// libft
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(char *str);

#endif
