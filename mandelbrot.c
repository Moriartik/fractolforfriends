/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:09:52 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 17:06:58 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pix		ft_mandel_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_comp	z;
	t_comp	c;
	t_comp	temp;
	int		i;

	(void)mlx;
	z = ft_screen_to_comp(x, y, v);
	c = ft_screen_to_comp(x, y, v);
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

void		ft_mandel_view(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
}
