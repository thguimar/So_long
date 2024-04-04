/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:53:37 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/04 19:21:44 by thguimar         ###   ########.fr       */
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
	printf("Unknown element '%c'", c);
	exit (1);
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
	if (map[y][x] == '1' || map[y][x] == 'W')
		return ;
	map[y][x] = 'W';
	flood_fill(map, (x + 1), y);
	flood_fill(map, (x - 1), y);
	flood_fill(map, x, (y + 1));
	flood_fill(map, x, (y - 1));
}

int	check_c(char **map)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		while (map[i][n] != '\0' && map[i][n] != '\n')
		{
			n++;
			if (map[i][n] == 'C')
			{
				printf("YOU FRICKING BASTARD!");
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	return (1);
}

int	check_e(char **map)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		while (map[i][n] != '\0' && map[i][n] != '\n')
		{
			n++;
			if (map[i][n] == 'E')
			{
				printf("YOU FRICKING BASTARD!");
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
	map.y = get_height(vars->map);
	while (map.y--)
	{
		map.x = 0;
		while (vars->map[map.y][map.x] != '\0')
		{
			if  (vars->map[map.y][map.x] == 'E')
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
	if(map.l == 1)
			vars->lantern++;
	if (map.e == 0 || map.p == 0 || map.c == 0 || map.p > 1 || map.l > 1 || map.e > 1)
		ft_error(vars, err_message(&map));
}
