/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:45:32 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 16:50:24 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_lerpi(int x, int y, double p)
{
	if (x == y)
		return (x);
	return (x + (y - x) * p);
}

int		ft_color(t_pix p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport.max)
		return (0x000000);
	if (mlx->smooth)
		return (ft_smooth_color(p, mlx->viewport.max, mlx->palette).value);
	return (ft_linear_color((double)p.i, mlx->viewport.max,
	mlx->palette).value);
}

t_color	ft_linear_color(double i, int max, t_palette *p)
{
	double		index;
	double		adjust;
	int			c;

	if (p->cycle)
		index = fmod(i, p->cycle - 1) / (p->cycle - 1);
	else
		index = i / max;
	c = p->count - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (ft_clerp((t_color)(p->colors[(int)(index * c) + 1]),
		(t_color)(p->colors[(int)(index * c) + 1]),
		(int)(adjust + 1) - adjust));
}

t_color	ft_smooth_color(t_pix p, int max, t_palette *pal)
{
	double		i;
	double		zn;
	double		nu;

	i = 0;
	zn = log(p.y.a * p.y.a + p.y.b * p.y.b) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.i + i - nu;
	if (i < 0)
		i = 0;
	return (ft_linear_color(i, max, pal));
}

t_color	ft_clerp(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}
