/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:35:34 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/22 15:19:39 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collected(t_vars *v)
{
	v->collect--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
	if (v->collect == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->assets->gwd->img,
			v->e_x, v->e_y);
}

void	move_left(t_vars *v)
{
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) - 1] == 'E')
		exit_verifier(v, 0, 0);
	else if (v->map[(v->y_p / 32)][(v->x_p / 32) - 1] != '1')
	{
		v->x_p -= 32;
		put_text(v);
	}
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'C')
		collected(v);
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'L')
		lantern(v);
	v->left = 1;
	if (v->there_was_lantern == 1 && v->lantern == 0)
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwcwl2->img,
			v->x_p, v->y_p);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwc2->img,
			v->x_p, v->y_p);
}

void	move_right(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) + 1] == 'E')
		exit_verifier(v, 0, 1);
	else if (v->map[(v->y_p / 32)][(v->x_p / 32) + 1] != '1')
	{
		v->x_p += 32;
		put_text(v);
	}
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'C')
		collected(v);
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'L')
		lantern(v);
	v->left = 0;
	if (v->there_was_lantern == 1 && v->lantern == 0)
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwcwl->img,
			v->x_p, v->y_p);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwc->img,
			v->x_p, v->y_p);
}

void	move_up(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->ground->img, v->x_p, v->y_p);
	if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] == 'E')
		exit_verifier(v, 1, 0);
	else if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] != '1')
	{
		(v)->y_p -= 32;
		put_text(v);
	}
	move_idk(v);
}

void	move_down(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] == 'E')
		exit_verifier(v, 1, 1);
	else if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] != '1')
	{
		v->y_p += 32;
		put_text(v);
	}
	move_idk(v);
}
