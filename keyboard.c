/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:12:54 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 17:12:55 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int		ft_draw_hooks(int key, t_mlx *mlx)
{
	int		doot;

	doot = 0;
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 3)
		mlx->palette = &ft_get_palettes()[key - K_DIGIT_1];
	else if (key == K_NUM_ENTER)
		mlx->smooth = 1 - mlx->smooth;
	else
		doot = 1;
	if (!doot)
		ft_draw(mlx);
	return (doot);
}

void	ft_move(int key, t_mlx *mlx)
{
	double w;
	double h;

	w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
	h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
	if (key == K_UP)
		mlx->viewport.offy -= h * 0.05f;
	if (key == K_DOWN)
		mlx->viewport.offy += h * 0.05f;
	if (key == K_LEFT)
		mlx->viewport.offx -= w * 0.05f;
	if (key == K_RIGHT)
		mlx->viewport.offx += w * 0.05f;
	if (key == K_L)
		mlx->mouselock = 1 - mlx->mouselock;
}

int		ft_hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_NUM_0)
		ft_reset_viewport(mlx);
	if (key == K_NUM_MULT)
		mlx->viewport.max *= 2;
	if (key == K_NUM_DIV)
		if (mlx->viewport.max / 2 >= 2)
			mlx->viewport.max /= 2;
	if (key == K_NUM_PLUS)
		ft_zoom(1280 / 2, 720 / 2, &mlx->viewport, 1 / 1.1f);
	if (key == K_NUM_MINUS)
		ft_zoom(1280 / 2, 720 / 2, &mlx->viewport, 1.1f);
	ft_move(key, mlx);
	if (ft_draw_hooks(key, mlx))
		ft_render(mlx);
	return (0);
}
