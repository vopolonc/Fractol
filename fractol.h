/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:54:49 by vopolonc          #+#    #+#             */
/*   Updated: 2019/04/07 14:43:52 by vopolonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>
# include "libft/libft.h"

/*
** Window settings
*/

# define FPI		300
# define W_HEI		700
# define W_WID		700
# define W_NAME		"fractol"
# define WC			0xFF0000

/*
** Keys macroses
*/

# define ESC		53
# define SPACE		49
# define TAB		48
# define Z_PLUS		4
# define Z_MINUS	5
# define I_PLUS		69
# define I_MINUS	78
# define K_RIGHT	124
# define K_LEFT		123
# define K_DOWN		125
# define K_UP		126
# define K_ONE		83
# define K_TWO		84
# define K_THREE	85
# define K_FOUR		86
# define K_FIVE		87
# define K_SIX		88
# define K_SEVEN	89
# define K_EIGHT	91
# define K_NINE		92
# define K_R		15
# define K_TAB 		48

/*
** Function marcoses
*/

# define NEW_NAME ft_strdup(name)
# define POW(a) (a * a)
# define TIMER ((clock() - e->clocks)) / CLOCKS_PER_SEC

/*
** Main struct
*/

typedef struct	s_envi
{
	clock_t		clocks;
	short		pass;
	char		*line;
	char		*name;
	void		*mlx;
	void		*win;
	void		*image;
	double		c_a;
	double		c_b;
	double		zoom;
	double		x;
	double		y;
	double		s_tree;
	double		ss_tree;
	int			r;
	int			g;
	int			b;
	int			bpp;
	int			sl;
	int			endian;
	int			pad;
	int			pow;
	int			cot;
	int			cordon;
	int			tr;
	int			bck;
	int			iters;
	int			menu;
}				t_envi;

/*
** cordinates struct
*/

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

/*
** main.c
*/

t_envi			*init_e(t_envi *e, char *name);
void			error_msg(void);
void			menu_s(t_envi *e);
int				destroy(void);

/*
**drawer.c
*/

void			pixfull2(t_envi *e, int x, int y, int clr);
void			pixfull(t_envi *e, int xy[2], int clr);
void			draw_fr(t_envi *e);
void			draw_tr(t_envi *e, t_point *p, double ang, int iters);
void			draw_into_image(t_envi *e);

/*
**prototypes of fractols   fractaols_mandatory.c
*/

void			chapter_of_tree(t_envi *e,
								t_point *p, t_point *l_p, int color);
int				ship_init(t_envi *e, int xy[2]);
int				mandelbrot_init(t_envi *e, int xy[2]);
int				julia_init(t_envi *e, int xy[2]);
int				fract_1(t_envi *e, int xy[2]);
int				fract_2(t_envi *e, int xy[2]);
int				fract_3(t_envi *e, int xy[2]);
int				fract_4(t_envi *e, int xy[2]);

/*
**initializing.c
*/

void			drawer(t_envi *e);
int				expose_hook(t_envi *e);
void			init_fract(t_envi *e, int pass);
void			prs(t_envi *e);
int				chose_ur_character(t_envi *e, int xy[2]);

/*
** hooker.c
*/

void			reset_e(t_envi *e);
int				mouse2(int b, int x, int y, t_envi *e);
int				mouse1(int x, int y, t_envi *e);
int				key_hook(int k, t_envi *e);
int				key_hoolder(int k, t_envi *e);

#endif
