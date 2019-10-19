/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:54:35 by vopolonc          #+#    #+#             */
/*   Updated: 2019/03/28 15:54:44 by vopolonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					destroy(void)
{
	exit(1);
	return (0);
}

void				menu_s(t_envi *e)
{
	char *arr;

	arr = ft_itoa(e->iters);
	mlx_string_put(e->mlx, e->win, 10, 120, WC, "--------------");
	mlx_string_put(e->mlx, e->win, 10, 135, WC, "INFO");
	mlx_string_put(e->mlx, e->win, 10, 150, WC, "--------------");
	mlx_string_put(e->mlx, e->win, 10, 170, WC, "MOVE : ARROWS");
	mlx_string_put(e->mlx, e->win, 10, 190, WC, "--------------");
	mlx_string_put(e->mlx, e->win, 10, 210, WC, "COLORS : 1 - 8");
	mlx_string_put(e->mlx, e->win, 10, 230, WC, "--------------");
	mlx_string_put(e->mlx, e->win, 10, 250, WC, "RESET : R");
	mlx_string_put(e->mlx, e->win, 10, 270, WC, "--------------");
	mlx_string_put(e->mlx, e->win, 10, 290, WC, "Toggle : SPACE");
	mlx_string_put(e->mlx, e->win, 10, 310, WC, "dynamic");
	mlx_string_put(e->mlx, e->win, 10, 330, WC, "--------------");
	mlx_string_put(e->mlx, e->win, 10, 350, WC, "ITERS : +/-");
	mlx_string_put(e->mlx, e->win, 10, 370, WC, arr);
	mlx_string_put(e->mlx, e->win, 10, 390, WC, "--------------");
	mlx_string_put(e->mlx, e->win, 10, 410, WC, "FRACTOLS :|A|S|");
	mlx_string_put(e->mlx, e->win, 10, 430, WC, "|D|F|G|X|C| ");
	free(arr);
}

void				error_msg(void)
{
	printf("Usage : ./fractol [Julia, Mandelbrot, Ship, Tree, Fractol-1..4]\n");
	exit(1);
}

t_envi				*init_e(t_envi *e, char *name)
{
	e->name = NEW_NAME;
	e->image = NULL;
	e->win = NULL;
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
	e->r = 5;
	e->g = 1;
	e->b = 3;
	e->tr = 0;
	e->cot = 1;
	e->menu = 1;
	return (e);
}

int					main(int ac, char **av)
{
	t_envi			*e;

	e = (t_envi*)malloc(sizeof(t_envi));
	(ac != 2) ? error_msg() : prs(init_e(e, av[1]));
	return (0);
}
