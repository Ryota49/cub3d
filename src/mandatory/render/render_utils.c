/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byonis <byonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:52:40 by byonis            #+#    #+#             */
/*   Updated: 2026/07/21 10:05:03 by byonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

mlx_color	color_to_mlx_color(t_colors c)
{
	mlx_color	res;

	res.r = c.r;
	res.g = c.g;
	res.b = c.b;
	res.a = 255;
	return (res);
}

void	put_pixel_to_buffer(t_game *g, int x, int y, mlx_color color)
{
	if (x >= 0 && x < g->screen_w && y >= 0 && y < g->screen_h)
		g->screen_pix[y * g->screen_w + x] = color;
}
