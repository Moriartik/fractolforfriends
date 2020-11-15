/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:45:05 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 17:24:55 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_viewport_podgon(t_viewport *v)
{
	double width;
	double height;

	width = v->xmax - v->xmin;
	height = v->ymax - v->ymin;
	if (width / height >= (float)1280 / 720)
	{
		v->ymin = -(width * 720 / 1280 / 2);
		v->ymax = (width * 720 / 1280 / 2);
	}
	else
	{
		v->xmin = -(height * 1280 / 720 / 2);
		v->xmax = (height * 1280 / 720 / 2);
	}
}

void		ft_reset_viewport(t_mlx *mlx)
{
	mlx->viewport.offx = 0;
	mlx->viewport.offy = 0;
	mlx->frac->viewport(&mlx->viewport);
	ft_viewport_podgon(&mlx->viewport);
	mlx->viewport.max = 128;
	mlx->viewport.zoom = 1.0f;
}
