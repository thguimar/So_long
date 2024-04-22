/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:21:55 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/22 15:23:08 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_xloop(t_vars *vars, int x1, int y1, int map_y)
{
	int	map_x;

	map_x = 0;
	if (vars->map[map_y] == NULL)
	{
		final_cleaner(vars, 1);
		exit (1);
	}
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

void	exit_verifier(t_vars *v, int xy, int vet)
{
	if (v->collect <= 0)
		exit_door(v);
	else
	{
		if (xy == 0)
		{
			if (vet == 0)
				v->x_p -= 32;
			else if (vet == 1)
				v->x_p += 32;
		}
		else if (xy == 1)
		{
			if (vet == 0)
				v->y_p -= 32;
			else if (vet == 1)
				v->y_p += 32;
		}
	}
}

void	invisible_door(t_vars *v, int x1, int y1)
{
	mlx_put_image_to_window(v->mlx, v->win, v->assets->ground->img, x1, y1);
	v->e_x = x1;
	v->e_y = y1;
}
