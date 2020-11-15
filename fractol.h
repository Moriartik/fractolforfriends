/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:12:35 by aghar             #+#    #+#             */
/*   Updated: 2020/08/05 16:59:45 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include "minilibx/mlx.h"
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>

typedef struct			s_comp
{
	double		a;
	double		b;
}						t_comp;

typedef struct s_mlx	t_mlx;

typedef struct			s_viewport
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	t_comp		mouse;
}						t_viewport;

typedef struct			s_pix
{
	t_comp		y;
	long		i;
}						t_pix;

typedef void			(*t_v)(t_viewport *v);

typedef t_pix			(*t_p)(int x, int y, t_viewport *v, t_mlx *mlx);

typedef struct			s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}						t_mouse;

typedef struct			s_thread
{
	int			id;
	t_mlx		*mlx;
}						t_thread;

typedef struct			s_ren
{
	pthread_t	threads[8];
	t_thread	args[8];
}						t_ren;

typedef struct			s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}						t_image;

typedef struct			s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}						t_rgba;

typedef union			u_color
{
	int			value;
	t_rgba		rgba;
}						t_color;

typedef struct			s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}						t_palette;

typedef struct			s_fractol
{
	char		*name;
	t_v			viewport;
	t_p			pixel;
	int			mouse;
}						t_fractol;

struct					s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	t_fractol	*frac;
	t_pix		*data;
	t_viewport	viewport;
	t_ren		ren;
	t_mouse		mouse;
	t_palette	*palette;
	int			smooth;
	int			mouselock;
	int			exp;
};

int						ft_end(char *str);
t_fractol				*ft_fractal_start(char *str);
t_image					*ft_del_image(t_mlx *mlx, t_image *image);
t_mlx					*ft_mlx_del(t_mlx *mlx);
t_mlx					*ft_init_mlx(t_fractol *f);
t_image					*ft_new_image(t_mlx *mlx);
int						ft_color(t_pix p, t_mlx *mlx);
t_color					ft_linear_color(double i, int max, t_palette *p);
t_color					ft_smooth_color(t_pix p, int max, t_palette *pal);
t_color					ft_clerp(t_color c1, t_color c2, double p);
void					*ft_render_thread(void *m);
void					ft_render(t_mlx *mlx);
void					ft_draw(t_mlx *mlx);
t_fractol				*ft_getf(void);
t_fractol				*ft_fractal_start(char *str);
t_image					*ft_del_image(t_mlx *mlx, t_image *image);
t_image					*ft_new_image(t_mlx *mlx);
void					ft_im_put_pix(t_image *image, int x, int y, int color);
void					ft_cleari(t_image *image);
t_pix					ft_julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void					ft_julia_view(t_viewport *v);
int						ft_draw_hooks(int key, t_mlx *mlx);
void					ft_move(int key, t_mlx *mlx);
int						ft_hook_keydown(int key, t_mlx *mlx);
t_pix					ft_mandel_pixel(int x, int y,
						t_viewport *v, t_mlx *mlx);
void					ft_mandel_view(t_viewport *v);
int						ft_hook_mousedown(int button, int x, int y, t_mlx *mlx);
int						ft_hook_mouseup(int button, int x, int y, t_mlx *mlx);
int						ft_hook_mousemove(int x, int y, t_mlx *mlx);
t_palette				*ft_get_palettes(void);
void					ft_viewport_podgon(t_viewport *v);
void					ft_reset_viewport(t_mlx *mlx);
t_mlx					*ft_mlx_del(t_mlx *mlx);
t_mlx					*ft_init_mlx(t_fractol *f);
int						ft_hook_expose(t_mlx *mlx);
void					ft_zoom(int x, int y, t_viewport *v, double z);
t_comp					ft_screen_to_comp(int x, int y, t_viewport *v);
void					ft_draw_menu(t_mlx *mlx);
t_pix					ft_expn_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void					ft_expn_view(t_viewport *v);
t_comp					ft_next_seq(t_comp z);
t_comp					ft_comp_div(t_comp t1, t_comp t2);
t_comp					ft_cabs(t_comp z, int n);
t_pix					ft_burning_pixel(int x, int y, t_viewport *v,
t_mlx *mlx);
void					ft_burning_view(t_viewport *v);

#endif
