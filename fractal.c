/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:45:09 by aghar             #+#    #+#             */
/*   Updated: 2020/08/05 16:45:53 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*ft_getf(void)
{
	static t_fractol mas[8] = {
		{"mandelbrot", ft_mandel_view, ft_mandel_pixel, 0},
		{"julia", ft_julia_view, ft_julia_pixel, 1},
		{"burningship", ft_burning_view, ft_burning_pixel, 0},
		{"exp", ft_expn_view, ft_expn_pixel, 1},
		{NULL, NULL, NULL, 0}
	};

	return (mas);
}

t_fractol	*ft_fractal_start(char *str)
{
	t_fractol	*f;
	int			i;

	f = ft_getf();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}
