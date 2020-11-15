/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:41:32 by aghar             #+#    #+#             */
/*   Updated: 2020/08/05 16:59:16 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pix		ft_burning_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_comp	z;
	t_comp	c;
	t_comp	temp;
	int		i;

	(void)mlx;
	z = ft_screen_to_comp(x, y, v);
	c = ft_screen_to_comp(x, y, v);
	i = 0;
	while (z.a * z.a + z.b * z.b < (1 << 8) && i++ < v->max)
	{
		if (z.a < 0)
			z.a = -z.a;
		if (z.b < 0)
			z.b = -z.b;
		temp.a = z.a * z.a - z.b * z.b + c.a;
		temp.b = z.a * z.b * 2 + c.b;
		if (z.a == temp.a && z.b == temp.b)
			i = v->max;
		z.a = temp.a;
		z.b = temp.b;
	}
	return ((t_pix){.y = z, .i = i});
}

void		ft_burning_view(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
}
