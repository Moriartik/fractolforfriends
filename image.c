/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:44:50 by aghar             #+#    #+#             */
/*   Updated: 2020/08/04 14:24:33 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*ft_del_image(t_mlx *mlx, t_image *image)
{
	if (image != NULL)
	{
		if (image->image != NULL)
			mlx_destroy_image(mlx->mlx_ptr, image->image);
		ft_memdel((void**)&image);
	}
	return (NULL);
}

t_image		*ft_new_image(t_mlx *mlx)
{
	t_image		*image;

	if ((image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((image->image = mlx_new_image(mlx->mlx_ptr, 1280, 720)) == NULL)
		return (ft_del_image(mlx, image));
	image->ptr = mlx_get_data_addr(image->image,
		&image->bpp, &image->stride, &image->endian);
	image->bpp /= 8;
	return (image);
}

void		ft_im_put_pix(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= 1280 || y < 0 || y >= 720)
		return ;
	*(int*)(image->ptr + ((x + y * 1280) * image->bpp)) = color;
}

void		ft_cleari(t_image *image)
{
	ft_bzero(image->ptr, 1280 * 720 * image->bpp);
}
