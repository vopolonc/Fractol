/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:26:42 by vopolonc          #+#    #+#             */
/*   Updated: 2019/04/07 14:11:59 by vopolonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				pixfull(t_envi *e, int xy[2], int clr)
{
	int				rgb[3];

	rgb[0] = (clr & 0xFF0000) >> 16;
	rgb[1] = (clr & 0xFF00) >> 8;
	rgb[2] = (clr & 0xFF);
	if (xy[0] >= 0 && xy[1] && xy[0] < W_WID && xy[1] < W_HEI)
	{
		e->line[(xy[1] * e->sl) + ((e->bpp / 8) * xy[0]) + 2] = rgb[0];
		e->line[(xy[1] * e->sl) + ((e->bpp / 8) * xy[0]) + 1] = rgb[1];
		e->line[(xy[1] * e->sl) + ((e->bpp / 8) * xy[0])] = rgb[2];
	}
}

void				pixfull2(t_envi *e, int x, int y, int clr)
{
	int				rgb[3];

	rgb[0] = (clr & 0xFF0000) >> 16;
	rgb[1] = (clr & 0xFF00) >> 8;
	rgb[2] = (clr & 0xFF);
	if (x >= 0 && y && x < W_WID && y < W_HEI)
	{
		e->line[(y * e->sl) + ((e->bpp / 8) * x) + 2] = rgb[0];
		e->line[(y * e->sl) + ((e->bpp / 8) * x) + 1] = rgb[1];
		e->line[(y * e->sl) + ((e->bpp / 8) * x)] = rgb[2];
	}
}

void				draw_fr(t_envi *e)
{
	int				xy[2];
	int				k;
	int				clr;

	xy[1] = -1;
	k = 0;
	while (++xy[1] < W_HEI && (xy[0] = -1))
		while (++xy[0] < W_WID)
		{
			k = chose_ur_character(e, xy);
			clr = ((255 - k * e->r) << 16) + ((255 - k * e->g) << 8)
				+ (255 - k * e->b);
			(e->iters != k) ? pixfull(e, xy, clr) : e->iters;
		}
}

void				draw_tr(t_envi *e, t_point *p, double ang, int iters)
{
	t_point			*l_p;
	int				color;

	color = 0;
	l_p = (t_point*)malloc(sizeof(t_point));
	if (iters > 0)
	{
		l_p->x = p->x + (cos(ang) * iters * 6) * e->zoom;
		l_p->y = p->y + (sin(ang) * iters * 9) * e->zoom;
		color = ((50 + e->r * iters) << 16) + ((e->g * iters) << 8)
			+ (155 - e->b * iters);
		chapter_of_tree(e, p, l_p, color << 4);
		draw_tr(e, l_p, ang - (M_PI / 8 * e->s_tree * 2), iters - 1);
		draw_tr(e, l_p, ang + (M_PI / 8 * e->ss_tree * 2), iters - 1);
	}
	free(l_p);
}

void				draw_into_image(t_envi *e)
{
	t_point			*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = W_WID / 2 - (e->x * (e->zoom / 3.0));
	point->y = W_HEI - 20 + (e->y * (e->zoom / 1.5));
	e->line = mlx_get_data_addr(e->image, &e->bpp, &e->sl, &e->endian);
	(e->tr) ? draw_tr(e, point, -(M_PI / 2), e->iters) : draw_fr(e);
	free(point);
}
