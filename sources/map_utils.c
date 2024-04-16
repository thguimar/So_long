/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:53:37 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/16 23:31:52 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*err_message(t_map *map)
{
	if (map->c == 0)
		return ("Error: missing 'C' element");
	else if (map->e == 0)
		return ("Error: missing 'E' element");
	else if (map->p == 0)
		return ("Error: missing 'P' element");
	else if (map->p > 1)
		return ("Error: there is more than one 'P' element");
	else if (map->l > 1)
		return ("Error: there is more than one 'L' element");
	else if (map->e > 1)
		return ("Error: there is more than one 'E' element");
	return ("Error: missing map");
}

void	flood_fill(char **map, int x, int y)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (map[h][w] != '\0' && map[h][w] != '\n')
		w++;
	while (map[h])
		h++;
	if (x < 0 || y < 0 || x >= w || y >= h)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, (x + 1), y);
	flood_fill(map, (x - 1), y);
	flood_fill(map, x, (y + 1));
	flood_fill(map, x, (y - 1));
}

int	check_c(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n - 1] == 'C')
			{
				ft_printf("YOU IDIOT!");
				final_cleaner(vars, 2);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	return (1);
}

int	check_e(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n] == 'E')
			{
				ft_printf("YOU IDIOT!");
				final_cleaner(vars, 2);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	return (1);
}

void	check_elements(t_vars *vars)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.l = 0;
	map.y = get_height(vars->map);
	map = map_idk(vars, map);
	if (map.l == 1)
		vars->lantern++;
	if (map.e == 0 || map.p == 0 || map.c == 0 || map.p > 1
		|| map.l > 1 || map.e > 1)
		ft_error(vars, err_message(&map));
}
