/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_secondly.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:07:17 by vopolonc          #+#    #+#             */
/*   Updated: 2019/04/07 14:27:57 by vopolonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					fract_2(t_envi *e, int xy[2])
{
	double			w_h[2];
	double			cur;
	int				k;

	cur = 0.0;
	k = 0;
	w_h[0] = ((4 * (double)xy[0] / W_WID - 2) / e->zoom) + (e->x / W_WID);
	w_h[1] = ((-4 * (double)xy[1] / W_HEI + 2) / e->zoom) + (e->y / W_HEI);
	while (POW(w_h[0]) + POW(w_h[1]) <= 4 && k < e->iters)
	{
		cur = w_h[0];
		w_h[0] = sin(POW(w_h[0]) - POW(w_h[1])) + e->c_a;
		w_h[1] = 2 * cur * w_h[1] + e->c_b;
		k++;
	}
	return (k);
}

int					fract_3(t_envi *e, int xy[2])
{
	double			zab[2];
	double			cur;
	int				k;

	e->c_a = 1.5 * (xy[0] - W_WID / 2) / (0.5 * e->zoom * W_WID)
		+ (e->x / W_WID / 1.37);
	e->c_b = 1.5 * (xy[1] - W_HEI / 2) / (0.5 * e->zoom * W_HEI)
		- (e->y / W_HEI / 1.92);
	zab[0] = 0.0;
	zab[1] = 0.0;
	k = -1;
	while (POW(zab[0]) + POW(zab[1]) <= 4 && ++k < e->iters)
	{
		cur = zab[0];
		zab[0] = POW(cur) - POW(zab[1]) + e->c_a;
		zab[1] = -(2 * cur * zab[1] + e->c_b);
	}
	return (k);
}

int					fract_4(t_envi *e, int xy[2])
{
	double			w_h[2];
	double			cur;
	int				k;

	cur = 0.0;
	k = 0;
	w_h[0] = ((4 * (double)xy[0] / W_WID - 2) / e->zoom) + (e->x / W_WID);
	w_h[1] = ((-4 * (double)xy[1] / W_HEI + 2) / e->zoom) + (e->y / W_HEI);
	while (POW(w_h[0]) + POW(w_h[1]) <= 4 && k < e->iters)
	{
		cur = w_h[0];
		w_h[0] = fabs(POW(w_h[0]) - POW(w_h[1]) + e->c_a);
		w_h[1] = 2.77 * cur * w_h[1] + e->c_b;
		k++;
	}
	return (k);
}

void				chapter_of_tree(t_envi *e, t_point *p,
	t_point *l_p, int color)
{
	double			dd;
	double			xy[2];
	double			dxy[2];

	xy[0] = p->x;
	xy[1] = p->y;
	dxy[0] = l_p->x - p->x;
	dxy[1] = l_p->y - p->y;
	dd = sqrt((POW(dxy[0])) + (POW(dxy[1])));
	dxy[0] = dxy[0] / dd;
	dxy[1] = dxy[1] / dd;
	while (dd-- >= 0)
	{
		pixfull2(e, xy[0], xy[1], color);
		xy[0] += dxy[0];
		xy[1] += dxy[1];
	}
}
