/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_mandatory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:59:56 by vopolonc          #+#    #+#             */
/*   Updated: 2019/04/07 14:26:11 by vopolonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ship_init(t_envi *e, int xy[2])
{
	double			zab[2];
	double			cur;
	int				k;

	e->c_a = 1.5 * (xy[0] - W_WID / 2) / (0.5 * e->zoom * W_WID)
		+ (e->x / W_WID / 1.30) - 0.5;
	e->c_b = (xy[1] - W_HEI / 2) / (0.5 * e->zoom * W_HEI)
		- (e->y / W_HEI / 1.97);
	zab[0] = 0.0;
	zab[1] = 0.0;
	k = -1;
	while (POW(zab[0]) + POW(zab[1]) <= 4 && ++k < e->iters)
	{
		cur = zab[0];
		zab[0] = fabs(POW(cur)) - POW(zab[1]) + e->c_a;
		zab[1] = 3 * fabs(cur * zab[1]) + e->c_b;
	}
	return (k);
}

int					fract_1(t_envi *e, int xy[2])
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
		w_h[0] = POW(w_h[0]) - POW(w_h[1]) + e->c_a;
		w_h[1] = 2 * cos(cur * w_h[1]) + e->c_b;
		k++;
	}
	return (k);
}

int					mandelbrot_init(t_envi *e, int xy[2])
{
	double			zab[2];
	double			cur;
	int				k;

	e->c_a = 1.5 * (xy[0] - W_WID / 2) / (0.5 * e->zoom * W_WID)
		+ (e->x / W_WID / 1.37) - 0.5;
	e->c_b = (xy[1] - W_HEI / 2) / (0.5 * e->zoom * W_HEI)
		- (e->y / W_HEI / 1.92);
	zab[0] = 0.0;
	zab[1] = 0.0;
	k = -1;
	while (POW(zab[0]) + POW(zab[1]) <= 4 && ++k < e->iters)
	{
		cur = zab[0];
		zab[0] = POW(cur) - POW(zab[1]) + e->c_a;
		zab[1] = 2 * cur * zab[1] + e->c_b;
	}
	return (k);
}

int					julia_init(t_envi *e, int xy[2])
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
		w_h[0] = POW(w_h[0]) - POW(w_h[1]) + e->c_a;
		w_h[1] = 2 * cur * w_h[1] + e->c_b;
		k++;
	}
	return (k);
}
