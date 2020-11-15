/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:45:00 by aghar             #+#    #+#             */
/*   Updated: 2020/08/05 17:05:43 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_end(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int		ft_atoi_spec(char const *s)
{
	unsigned long		rez;
	unsigned long		maxval;
	size_t				i;
	int					sign;

	i = 0;
	sign = 1;
	rez = 0;
	maxval = 922337203685477580;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'
	|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		rez = rez * 10 + (s[i++] - '0');
	if (s[i] != '\0')
		return (0);
	return ((int)rez * sign);
}

void	ft_start(t_mlx *mlx)
{
	ft_reset_viewport(mlx);
	ft_draw_menu(mlx);
	ft_render(mlx);
	mlx_key_hook(mlx->win_ptr, ft_hook_keydown, mlx);
	mlx_expose_hook(mlx->win_ptr, ft_hook_expose, mlx);
	mlx_hook(mlx->win_ptr, 4, 1L << 2, ft_hook_mousedown, mlx);
	mlx_hook(mlx->win_ptr, 5, 1L << 3, ft_hook_mouseup, mlx);
	mlx_hook(mlx->win_ptr, 6, 1L << 6, ft_hook_mousemove, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractol	*f;

	if (argc < 2)
		return (ft_end("Error: non valid number of arguments\n"));
	if (argc != 2 && (ft_strcmp(argv[1], "exp") != 0))
		return (ft_end("Error: non valid number of arguments\n"));
	else
	{
		if (argc < 3 && ft_strcmp(argv[1], "exp") == 0)
			return (ft_end("Error: non valid number of arguments\n"));
	}
	f = ft_fractal_start(argv[1]);
	if (f->name == NULL)
		return (ft_end("Nonvalid name: mandelbrot, julia, exp, burningship\n"));
	if (ft_strcmp(argv[1], "exp") == 0)
		if (ft_atoi_spec(argv[2]) <= 1 || ft_atoi_spec(argv[2]) >= 15)
			return (ft_end("Wrong number of exp\n"));
	if ((mlx = ft_init_mlx(f)) == NULL)
		return (ft_end("Error: mlx init error\n"));
	if (ft_strcmp(argv[1], "exp") == 0)
		mlx->exp = ft_atoi(argv[2]);
	ft_start(mlx);
	return (0);
}

int		ft_hook_expose(t_mlx *mlx)
{
	ft_render(mlx);
	return (0);
}
