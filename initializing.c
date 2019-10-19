/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:22:53 by vopolonc          #+#    #+#             */
/*   Updated: 2019/04/07 14:14:20 by vopolonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					chose_ur_character(t_envi *e, int xy[2])
{
	int				i;

	i = 0;
	(e->pass == 1) ? i = julia_init(e, xy) : e->pass;
	(e->pass == 2) ? i = mandelbrot_init(e, xy) : e->pass;
	(e->pass == 3) ? i = ship_init(e, xy) : e->pass;
	(e->pass == 5) ? i = fract_1(e, xy) : e->pass;
	(e->pass == 6) ? i = fract_2(e, xy) : e->pass;
	(e->pass == 7) ? i = fract_3(e, xy) : e->pass;
	(e->pass == 8) ? i = fract_4(e, xy) : e->pass;
	return (i);
}

void				drawer(t_envi *e)
{
	e->image = mlx_new_image(e->mlx, W_WID, W_HEI);
	draw_into_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	(e->menu) ? menu_s(e) : e;
	mlx_destroy_image(e->mlx, e->image);
}

int					expose_hook(t_envi *e)
{
	drawer(e);
	return (0);
}

void				init_fract(t_envi *e, int pass)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W_WID, W_HEI, W_NAME);
	e->pass = pass;
	if (pass == 4)
	{
		e->tr = 1;
		e->iters = 10;
	}
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 0, key_hoolder, e);
	mlx_hook(e->win, 6, (1L << 6), mouse1, e);
	mlx_hook(e->win, 4, (1L << 2), mouse2, e);
	mlx_hook(e->win, 17, 0, destroy, NULL);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}

void				prs(t_envi *e)
{
	((ft_strequ(e->name, "Julia"))) ? init_fract(e, 1) : e;
	((ft_strequ(e->name, "Mandelbrot"))) ? init_fract(e, 2) : e;
	((ft_strequ(e->name, "Ship"))) ? init_fract(e, 3) : e;
	((ft_strequ(e->name, "Tree"))) ? init_fract(e, 4) : e;
	((ft_strequ(e->name, "Fractol-1"))) ? init_fract(e, 5) : e;
	((ft_strequ(e->name, "Fractol-2"))) ? init_fract(e, 6) : e;
	((ft_strequ(e->name, "Fractol-3"))) ? init_fract(e, 7) : e;
	((ft_strequ(e->name, "Fractol-4"))) ? init_fract(e, 8) : e;
	printf("Usage : ./fractol [Julia, Mandelbrot, Ship, Tree, Fractol-1..4]\n");
}
