/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:46:08 by aghar             #+#    #+#             */
/*   Updated: 2020/08/10 13:11:56 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*ft_mlx_del(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->image != NULL)
		ft_del_image(mlx, mlx->image);
	ft_memdel((void*)&mlx);
	return (NULL);
}

t_mlx		*ft_init_mlx(t_fractol *f)
{
	t_mlx	*mlx;
	char	*title;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	title = f->name;
	if ((mlx->mlx_ptr = mlx_init()) == NULL ||
		(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1280,
		920, title)) == NULL ||
		(mlx->image = ft_new_image(mlx)) == NULL ||
		(mlx->data = ft_memalloc(sizeof(t_pix) * 1280 * 720)) == NULL)
		return (ft_mlx_del(mlx));
	mlx->mouse.isdown = 0;
	mlx->frac = f;
	mlx->mouselock = 1 - f->mouse;
	mlx->palette = ft_get_palettes();
	mlx->smooth = 1;
	return (mlx);
}
