/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:18:39 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/16 23:32:05 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lantern(t_vars *v)
{
	v->lantern--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
}

char	unknown_element(t_vars *v, char c)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free (v->map);
	ft_printf("Unknown element '%c'", c);
	exit (1);
}

t_map	map_idk(t_vars *vars, t_map map)
{
	while (map.y--)
	{
		map.x = 0;
		while (vars->map[map.y][map.x] != '\0')
		{
			if (vars->map[map.y][map.x] == 'E')
				map.e++;
			else if (vars->map[map.y][map.x] == 'P')
				map.p++;
			else if (vars->map[map.y][map.x] == 'C')
				map.c++;
			else if (vars->map[map.y][map.x] == 'L')
				map.l++;
			else if (vars->map[map.y][map.x] != '1' &&
				vars->map[map.y][map.x] != '0')
				unknown_element(vars, vars->map[map.y][map.x]);
			map.x++;
		}
	}
	return (map);
}

void	move_idk(t_vars *v)
{
	if ((v)->map[((v)->y_p / 32)][((v)->x_p / 32)] == 'C')
		collected(v);
	if ((v)->map[((v)->y_p / 32)][((v)->x_p / 32)] == 'L')
		lantern(v);
	if (v->there_was_lantern == 1 && v->lantern == 0 && v->left == 0)
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwcwl->img,
			v->x_p, v->y_p);
	else if (v->left == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwc2->img, v->x_p, v->y_p);
		if (v->there_was_lantern == 1 && v->lantern == 0)
			mlx_put_image_to_window(v->mlx, v->win,
				v->assets->gwcwl2->img,
				v->x_p, v->y_p);
	}
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwc->img,
			v->x_p, v->y_p);
}

void	flood_checker(t_vars *vars, char **argv)
{
	get_player(vars);
	flood_fill(vars->map, vars->x_p, vars->y_p);
	check_c(vars);
	check_e(vars);
	final_cleaner(vars, 0);
	vars->map = get_map(argv[1], vars);
	vars->assets = malloc(sizeof(t_assets));
	assets_initiator(vars);
}
