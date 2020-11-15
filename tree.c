/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:51:34 by aghar             #+#    #+#             */
/*   Updated: 2020/08/04 14:55:51 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp		ft_cabs(t_comp z, int n)
{
	t_comp	local;
	double	help;
	int		k;

	k = 1;
	local = z;
	while (k < n)
	{
		help = local.a;
		local.a = local.a * z.a - local.b * z.b;
		local.b = help * z.b + z.a * local.b;
		k++;
	}
	return (local);
}

t_comp		ft_comp_div(t_comp t1, t_comp t2)
{
	t_comp local;

	local.a = t1.a * t2.a + t1.b * t2.b / (t2.a * t2.a + t2.b * t2.b);
	local.b = (t2.a * t1.b - t1.a * t2.b) / (t2.a * t2.a + t2.b * t2.b);
	return (local);
}
