/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:00:09 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/05 16:07:16 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_vars *vars, char *message)
{
	int	x;

	x = 0;
	while (vars->map[x])
	{
		free(vars->map[x]);
		x++;
	}
	free (vars->map);
	printf("%s", message);
	exit (1);
}

static void	check_is_rectangular(t_vars *vars)
{
	int	map_x;
	int	map_y;
	int	backup;
	int	height;

	map_y = 0;
	map_x = 0;
	backup = 0;
	height = get_height(vars->map);
	while (map_y != height)
	{
		while (vars->map[map_y][map_x] != '\0')
			map_x++;
		map_y++;
		if (backup != 0)
		{
			if (backup != map_x)
				ft_error(vars, "Error");
		}
		else
			backup = map_x;
	}
}

static int check_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != 49)
			return (1);
		i++;
	}
	return (0);
}

static void check_walls(t_vars *v)
{
	int	i;
	char	*message;

	message = "[ERROR] Not surrounded by walls";
	if (check_line(v->map[0]))
		ft_error (v, message);
	i = get_height(v->map) - 1;
	while (i)
	{
		if (v->map[i][0] != '1' ||
			v->map[i][ft_strlen(v->map[i]) - 1] != '1')
			ft_error(v, message);
		i--;
	}
	if (check_line(v->map[get_height(v->map) - 1]))
	{
		ft_error (v, message);
	}
}

void	check_map_valid(t_vars *vars)
{
	check_is_rectangular(vars);
	check_walls(vars);
	check_elements(vars);
}
