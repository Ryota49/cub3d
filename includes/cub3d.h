/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2026/06/24 13:36:59 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../MacroLibX-master/includes/mlx.h"
# include "get_next_line.h"

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

void	clean(t_game *g);

void	check_extension(char *map_file);
void    handle_error(char *msg_error);
size_t  ft_strlen(char *str);

#endif