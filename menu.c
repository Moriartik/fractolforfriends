/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:39:41 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 17:34:40 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 0,
			0xffffff,
			"Move  right/left/up/down or moving mousewith holding left button");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 20,
			0xffffff, "Zoom  mouse's roll or use +/-");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 40,
			0xffffff, "Choose color variation 1/2/3/4");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 60,
			0xffffff, "If you start a julia move your mouse to change c value");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 80,
			0xffffff, "If you want to reset view use '0' ");
}
