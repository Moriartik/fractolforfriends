/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exponentn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 13:21:02 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 17:12:15 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pix		ft_expn_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_comp	z;
	t_comp	c;
	t_comp	temp;
	t_comp	t1;
	int		i;

	(void)mlx;
	z = ft_screen_to_comp(x, y, v);
	c = v->mouse;
	i = 0;
	while (z.a * z.a + z.b * z.b < (1 << 8) && i < v->max)
	{
		t1 = ft_cabs(z, mlx->exp);
		temp.a = t1.a + c.a;
		temp.b = t1.b + c.b;
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

void		ft_expn_view(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}
