/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:07:07 by jemonthi          #+#    #+#             */
/*   Updated: 2026/08/19 22:46:11 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

static void	draw_minimap_square(t_game *g, int x0, int y0, mlx_color color)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->minimap.cell)
	{
		x = 0;
		while (x < g->minimap.cell)
		{
			put_pixel_to_buffer(g, x0 + x, y0 + y, color);
			x++;
		}
		y++;
	}
}

static mlx_color	get_minimap_color(char c)
{
	if (c == '1')
		return ((mlx_color){.r = 128, .g = 128, .b = 128, .a = 255});
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return ((mlx_color){.r = 0, .g = 128, .b = 0, .a = 255});
	return ((mlx_color){.r = 128, .g = 128, .b = 128, .a = 255});
}

static void	draw_p(t_game *g, int offset_x, int offset_y, int cell)
{
	int	player_x;
	int	player_y;

	player_x = offset_x + (int)(g->player.pos_x * cell);
	player_y = offset_y + (int)(g->player.pos_y * cell);
	if (cell < 2)
		cell = 2;
	draw_minimap_square(g, player_x - cell / 2, player_y - cell / 2,
		(mlx_color){.r = 255, .g = 0, .b = 0, .a = 255});
}

void	initialise_minimap(t_game *g)
{
	g->minimap.cell = 8;
	g->minimap.offset_x = 10;
	g->minimap.offset_y = 10;
	if (!g || !g->pars || !g->pars->real_map)
		return ;
	if (g->pars->width_max * g->minimap.cell > g->screen_w / 4
		|| g->pars->height_map * g->minimap.cell > g->screen_h / 4)
	{
		g->minimap.cell = g->screen_w / 4 / g->pars->width_max;
		if (g->minimap.cell < 1)
			g->minimap.cell = 1;
		if (g->pars->height_map * g->minimap.cell > g->screen_h / 4)
			g->minimap.cell = g->screen_h / 4 / g->pars->height_map;
		if (g->minimap.cell < 1)
			g->minimap.cell = 1;
	}
}

void	draw_minimap(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	if (!g || !g->pars || !g->pars->real_map)
		return ;
	while (y < g->pars->height_map)
	{
		x = 0;
		while (x < (int)ft_strlen(g->map[y]))
		{
			draw_minimap_square(g, g->minimap.offset_x + x * g->minimap.cell,
				g->minimap.offset_y + y * g->minimap.cell,
				get_minimap_color(g->map[y][x]));
			x++;
		}
		y++;
	}
	draw_p(g, g->minimap.offset_x, g->minimap.offset_y, g->minimap.cell);
}
