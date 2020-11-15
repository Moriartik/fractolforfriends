/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:13:31 by aghar             #+#    #+#             */
/*   Updated: 2020/08/04 14:07:07 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pix		ft_julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_comp	z;
	t_comp	c;
	t_comp	temp;
	int		i;

	(void)mlx;
	z = ft_screen_to_comp(x, y, v);
	c = v->mouse;
	i = 0;
	while (z.a * z.a + z.b * z.b < (1 << 8) && i < v->max)
	{
		temp.a = z.a * z.a - z.b * z.b + c.a;
		temp.b = z.a * z.b * 2 + c.b;
		if (z.a == temp.a && z.b == temp.b)
		{
			i = v->max;
			break ;
		}
		z.a = temp.a;
		z.b = temp.b;
		i++;
	}
	return ((t_pix){.y = z, .i = i});
}

void		ft_julia_view(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}

t_comp		ft_screen_to_comp(int x, int y, t_viewport *v)
{
	t_comp p;

	p.a = (((double)x / 1280) * (v->xmax - v->xmin)) * v->zoom
	+ v->xmin + v->offx;
	p.b = (((double)y / 720) * (v->ymax - v->ymin)) * v->zoom
	+ v->ymin + v->offy;
	return (p);
}
