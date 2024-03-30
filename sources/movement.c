/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:35:34 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/30 15:42:38 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void lantern(t_vars	*v)
{
	int		img_w;
	int		img_h;

	v->lantern--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
	v->img = mlx_xpm_file_to_image(
			v->mlx, "../assets/ground.xpm", &img_w, &img_h);
/*	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.wall->img, v->x_p, v->y_p);*/
}

static void	collected(t_vars *v)
{
	int		img_w;
	int		img_h;

	v->collect--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
	v->img = mlx_xpm_file_to_image(
			v->mlx, "../assets/ground.xpm", &img_w, &img_h);
/*	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character->img, v->x_p, v->y_p);*/
}

void	move_left(t_vars *v)
{
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) - 1] == 'E')
	{
		if (v->collect <= 0)
			exit_door(v);
	}
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
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_with_lantern2->img, v->x_p, v->y_p);
	else
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_left->img, v->x_p, v->y_p);
}

void	move_right(t_vars *v)
{
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) + 1] == 'E')
	{
		if (v->collect <= 0)
			exit_door(v);
	}
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
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_with_lantern->img, v->x_p, v->y_p);
	else
		mlx_put_image_to_window(
			v->mlx, v->win, v->assets.ground_with_character->img, v->x_p, v->y_p);
}

void	move_up(t_vars *v)
{
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground->img, v->x_p, v->y_p);
	if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] == 'E')
	{
		if ((v)->collect <= 0)
			exit_door(v);
	}
	else if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] != '1')
	{
		(v)->y_p -= 32;
		put_text(v);
	}
	if ((v)->map[((v)->y_p / 32)][((v)->x_p / 32)] == 'C')
		collected(v);
	if ((v)->map[((v)->y_p / 32)][((v)->x_p / 32)] == 'L')
		lantern(v);
	if (v->there_was_lantern == 1 && v->lantern == 0 && v->left == 0)
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_with_lantern->img, v->x_p, v->y_p);
	else if (v->left == 1)
	{
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_left->img, v->x_p, v->y_p);
		if (v->there_was_lantern == 1 && v->lantern == 0)
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_with_lantern2->img, v->x_p, v->y_p);
	}
	else
		mlx_put_image_to_window(
			v->mlx, v->win, v->assets.ground_with_character->img, v->x_p, v->y_p);
}

void	move_down(t_vars *v)
{
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] == 'E')
	{
		if (v->collect <= 0)
			exit_door(v);
	}
	else if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] != '1')
	{
		v->y_p += 32;
		put_text(v);
	}
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'C')
		collected(v);
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'L')
		lantern(v);
	if (v->there_was_lantern == 1 && v->lantern == 0 && v->left == 0)
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_with_lantern->img, v->x_p, v->y_p);
	else if (v->left == 1)
	{
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_left->img, v->x_p, v->y_p);
		if (v->there_was_lantern == 1 && v->lantern == 0)
		mlx_put_image_to_window(
		v->mlx, v->win, v->assets.ground_with_character_with_lantern2->img, v->x_p, v->y_p);
	}
	else
		mlx_put_image_to_window(
			v->mlx, v->win, v->assets.ground_with_character->img, v->x_p, v->y_p);
}
