/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:15:59 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/25 15:32:56 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "so_long.h"

static int	check(t_vars ***vars, int x, int y)
{
	if ((**vars)->map[y][x] == '0' && (**vars)->map[y][x + 1] == '0'
		&& (**vars)->map[y][x + 2] == '0')
	{
		(**vars)->e_vars.sign = 0;
		(**vars)->e_vars.x_e = x;
		(**vars)->e_vars.y_e = y;
		return (1);
	}
	return (0);
}

int	get_position_for_enemy(t_vars **vars)
{
	int			y;
	int			x;
	int			height;

	y = 0;
	height = get_height((*vars)->map);
	if ((*vars)->e_vars.sign)
	{
		while (y != height)
		{
			x = 0;
			while ((*vars)->map[y][x] != '\0')
			{
				if (check(&vars, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}
*/
