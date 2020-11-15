/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:00:51 by aghar             #+#    #+#             */
/*   Updated: 2020/08/02 14:41:10 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*ft_get_palettes(void)
{
	static t_palette	array[5];

	array[0] =
		(t_palette){5, 0, {0xF013D1, 0x053FF3, 0xEAF50E, 0xF39605, 0xF20B20}};
	array[1] =
		(t_palette){5, 0, {0x09A75D, 0xFFFD66, 0x0AEBFE, 0x0EE580, 0x04FF89}};
	array[2] =
		(t_palette){5, 0, {0xCDC707, 0xDD4407, 0xF165DA, 0x9825CD, 0xC326F9}};
	array[3] =
		(t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}
