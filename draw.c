/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:45:41 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 17:10:44 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_render_thread(void *m)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)m;
	y = 720 / 8 * t->id;
	while (y < 720 / 8 * (t->id + 1))
	{
		x = 0;
		while (x < 1280)
		{
			*(t->mlx->data + y * 1280 + x) =
			t->mlx->frac->pixel(x, y, &t->mlx->viewport, t->mlx);
			x++;
		}
		y++;
	}
	return (NULL);
}

void		ft_render(t_mlx *mlx)
{
	int		i;
	t_ren	*r;

	i = 0;
	r = &mlx->ren;
	while (i < 8)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		pthread_create(r->threads + i, NULL, ft_render_thread, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	ft_draw(mlx);
}

void		ft_draw(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < 720)
	{
		x = 0;
		while (x < 1280)
		{
			ft_im_put_pix(mlx->image, x, y, ft_color(*(mlx->data +
			y * 1280 + x), mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
	mlx->image->image, 0, 100);
}
