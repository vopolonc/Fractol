/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:31:16 by vopolonc          #+#    #+#             */
/*   Updated: 2019/04/02 16:31:26 by vopolonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				reset_e(t_envi *e)
{
	e->image = NULL;
	e->clocks = clock();
	e->zoom = 1.0;
	e->s_tree = 1.0;
	e->ss_tree = 1.0;
	e->c_b = 0.0;
	e->c_a = 0.0;
	e->x = 0.0;
	e->y = 0.0;
	e->iters = 100;
	e->pad = 10;
	e->r = 11;
	e->g = 1;
	e->b = 3;
	e->tr = 0;
	e->cot = 0;
	e->menu = 0;
	drawer(e);
}

int					key_hook(int k, t_envi *e)
{
	if (k == SPACE)
	{
		e->cot = e->cot ? 0 : 1;
	}
	(k == K_R && !e->tr) ? reset_e(e) : e;
	if (k == K_TAB)
	{
		e->menu = e->menu ? 0 : 1;
	}
	(k == 0) ? (e->pass = 1) : k;
	(k == 1) ? (e->pass = 2) : k;
	(k == 2) ? (e->pass = 3) : k;
	(k == 3) ? (e->pass = 5) : k;
	(k == 5) ? (e->pass = 6) : k;
	(k == 7) ? (e->pass = 7) : k;
	(k == 8) ? (e->pass = 8) : k;
	if ((k >= 0 && k <= 3) || (k >= 3 && k <= 8))
		reset_e(e);
	drawer(e);
	return (0);
}

int					key_hoolder(int k, t_envi *e)
{
	if (k == 53)
	{
		free(e->name);
		free(e);
		exit(1);
	}
	(k == K_ONE && e->r > 0) ? e->r++ : e->r;
	(k == K_TWO && e->r < 11) ? e->r-- : e->r;
	(k == K_FOUR && e->g > 0) ? e->g++ : e->g;
	(k == K_FIVE && e->g < 11) ? e->g-- : e->g;
	(k == K_SEVEN && e->b > 0) ? e->b++ : e->b;
	(k == K_EIGHT && e->b < 11) ? e->b-- : e->b;
	(k == K_DOWN) ? e->y += 25 / e->zoom : e->y;
	(k == K_UP) ? e->y -= 25 / e->zoom : e->y;
	(k == K_LEFT) ? e->x += 25 / e->zoom : e->x;
	(k == K_RIGHT) ? e->x -= 25 / e->zoom : e->x;
	(k == I_PLUS && e->iters < 500 && !e->tr) ? e->iters += 1 : e->iters;
	(k == I_MINUS && e->iters > 50 && !e->tr) ? e->iters -= 1 : e->iters;
	drawer(e);
	return (0);
}

int					mouse1(int x, int y, t_envi *e)
{
	if (((FPI * TIMER) > 1 && e->cot))
	{
		e->clocks = clock();
		x -= W_WID / 2;
		y -= W_HEI / 2;
		e->c_a = ((double)y / W_HEI);
		e->c_b = ((double)x / W_WID);
		drawer(e);
	}
	else if (((1000) * TIMER) > 1 && e->cot && e->tr)
	{
		e->clocks = clock();
		e->s_tree = (double)y / W_HEI;
		e->ss_tree = (double)x / W_WID;
		drawer(e);
	}
	return (0);
}

int					mouse2(int b, int x, int y, t_envi *e)
{
	x -= W_WID / 2;
	y -= W_HEI / 2;
	if (b == Z_PLUS)
	{
		e->zoom *= 1.1;
		e->x += x / e->zoom / 2.0;
		e->y -= y / e->zoom / 2.0;
		drawer(e);
	}
	else if (b == Z_MINUS && e->zoom > 0.01)
	{
		e->zoom /= 1.1;
		drawer(e);
	}
	return (0);
}
