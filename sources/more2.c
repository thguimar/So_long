/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:21:55 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/16 23:25:31 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_xloop(t_vars *vars, int x1, int y1, int map_y)
{
	int	map_x;

	map_x = 0;
	while (vars->win_w > 0)
	{
		put_image_to_map(vars->map[map_y][map_x], x1, y1, vars);
		vars->win_w--;
		map_x++;
		x1 += 32;
	}
	x1 = (map_x * 32);
	return (x1);
}

char	*nengue(int fd, char *line, char *all_lines)
{
	char	*temp;

	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
		{
			free(line);
			break ;
		}
		temp = ft_join_strings(all_lines, line);
		free(all_lines);
		all_lines = temp;
		free(line);
	}
	return (all_lines);
}
