/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/26 16:11:30 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../MacroLibX-master/includes/mlx.h"
# include "libft.h"
# include <stdio.h>

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}	t_player;

typedef struct s_ray
{
	float	camera_x;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
}	t_ray;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;

}	t_colors;

typedef struct s_game
{
	char		**map;
	char		*texture_n;
	char		*texture_s;
	char		*texture_e;
	char		*texture_w;
	void		*mlx;
	void		*win;
	int			screen_w;
	int			screen_h;
	t_player	player;
	t_colors	floor;
	t_colors	ceiling;
	int			boolean;
}	t_game;

typedef struct s_utils_parsing
{
	char	**splitter;
	char	*line;
	int		fd;
	int		count_no;
	int		count_so;
	int		count_we;
	int		count_ea;
	int		count_f;
	int		count_c;
	int		header_done;
	int		start_map;
	t_game	game;

}	t_utils_parsing;

// clean structure
void	clean(t_game *g);

// extension parsing
void	check_extension(char *map_file);

// open map_file and read line by line the header for now
void	open_file(t_utils_parsing *parsing, char *map_file);
void	manage_line(t_utils_parsing *parsing);
void	handle_splitter(t_utils_parsing *parsing);

//utils
void	remove_new_line(char *path);
void    count_comma(t_utils_parsing *parsing);

// free functions
void	free_splitter(char **splitter);

//check texture files and stock them inside game structure
void	check_path_texture_no(t_utils_parsing *parsing);
void	check_path_texture_so(t_utils_parsing *parsing);
void	check_path_texture_we(t_utils_parsing *parsing);
void	check_path_texture_ea(t_utils_parsing *parsing);

// check colors pattern and stock them inside game structure
void    check_color_f(t_utils_parsing *parsing);
void    check_color_c(t_utils_parsing *parsing);

// start finding the start of the map
void    find_start_map(t_utils_parsing *parsing);

// handle error
void	handle_error(char *msg_error);
void	err_free(char *msg, t_utils_parsing *parsing);
void	err_values(char *msg, t_utils_parsing *parsing, char **values);

// initialise structure
void	initialise_parsing(t_utils_parsing *parsing);
int		init_game(t_game *g);

// event
void	key_hook(int key, void *param);
// void	mouse_hook(int button, void *param);
void	window_hook(int event, void *param);

// Player
void	player_pos(t_game *game);

#endif
