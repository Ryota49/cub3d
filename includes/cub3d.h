/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/07/17 11:56:27 by byonis           ###   ########.fr       */
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
# include "../MacroLibX-master/includes/mlx_extended.h"
# include "libft.h"
# include <stdio.h>

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280

# define W_KEY 26
# define S_KEY 22
# define A_KEY 4
# define D_KEY 7
# define ESC_KEY 41
# define ROT_LEFT 80
# define ROT_RIGHT 79

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05

typedef struct s_utils_parsing t_utils_parsing;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

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
	int		step_x;
	int		step_y;
	int		map_y;
	int		map_x;
	int		pixel_start;
	int		pixel_end;
	float	wall_dist;
}	t_ray;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;

}	t_colors;

typedef struct s_game
{
	t_ray			ray;
	char			**map;
	char			*texture_n;
	char			*texture_s;
	char			*texture_e;
	char			*texture_w;
	void			*tex_north;
	void			*tex_south;
	void			*tex_east;
	void			*tex_west;
	void			*screen_img;
	mlx_color		*screen_pixels;
	int				img_width;
	int				img_height;
	void			*mlx;
	void			*win;
	int				screen_w;
	int				screen_h;
	t_player		player;
	t_colors		floor;
	t_colors		ceiling;
	int				boolean;
	t_utils_parsing	*pars;
	t_keys			keys;
}	t_game;

typedef struct s_character_map
{
	int	p_y;
	int	p_x;
	int	count_n;
	int	count_s;
	int	count_w;
	int	count_e;

}	t_character_map;

typedef struct s_utils_parsing
{
	char			**splitter;
	char			*line;
	int				fd;
	int				count_no;
	int				count_so;
	int				count_we;
	int				count_ea;
	int				count_f;
	int				count_c;
	int				header_done;
	int				start_map;
	char			**real_map;
	char			**cpy_map;
	int				line_read;
	int				height_map;
	int				width_max;
	t_game			game;
	t_character_map map;

}	t_utils_parsing;

// clean structure.
void	clean_game(t_game *g);
void	clean_parsing(t_utils_parsing *pars);

// extension parsing
void	check_extension(char *map_file);

// open map_file and read line by line the header for now
void	open_file(t_utils_parsing *parsing, char *map_file);
void	manage_line(t_utils_parsing *parsing);
void	handle_splitter(t_utils_parsing *parsing);

//utils
void	remove_new_line(char *path);
void    count_comma(t_utils_parsing *parsing);
void    find_longest_line(t_utils_parsing *parsing);

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

// start allocate into struct the map
void    allocate_map(t_utils_parsing *parsing, char *map_file);
void    create_copy_map(t_utils_parsing *parsing);
void	copy_real_map(t_utils_parsing *parsing);
void    find_player(t_utils_parsing *parsing);
void    check_player_character(t_utils_parsing *parsing);
void    check_count(t_utils_parsing *parsing);

// flood_fill
void	flood_fill(t_utils_parsing *parsing, int y, int x);
void	flood_fill_player(t_utils_parsing *parsing, int y, int x);

// handle error
void	handle_error(char *msg_error);
void	err_free(char *msg, t_utils_parsing *parsing);
void	err_map(char *msg, t_utils_parsing *parsing);

// initialise structure
void	initialise_parsing(t_utils_parsing *parsing);
int		init_game(t_game *g, t_utils_parsing *parsing);
void	init_ray(t_game *g, t_ray *ray, int x);

// event
// void	key_hook(int key, void *param);
// void	mouse_hook(int button, void *param);
void	key_down_hook(int key, void *param);
void	key_up_hook(int key, void *param);
void	window_hook(int event, void *param);

// Player
void	player_pos(t_game *game);

int		perform_dda(t_game *g, t_ray *ray);
float	calculate_wall_dist(t_ray *ray, int side);
void	calculate_pixel_start_end(t_game *g, t_ray *ray, float perp_wall_dist);
void	render(void *param);
void	update_movement(t_game *g);

#endif
