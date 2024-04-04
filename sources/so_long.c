/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:24:07 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/28 21:25:13 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	int	x;

	if (keycode == XK_d)
		move_right(vars);
	else if (keycode == XK_a)
		move_left(vars);
	else if (keycode == XK_w)
		move_up(vars);
	else if (keycode == XK_s)
		move_down(vars);
	else if (keycode == XK_Escape)
	{
		x = 0;
		while (vars->map[x])
		{
			free(vars->map[x]);
			x++;
		}
		free(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int	ft_exit(t_vars *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(1);
	return (0);
}

void	render_map(t_vars *vars)
{
	int	map_y;
	int	y1;
	int	backup_w;
	int	map_x;
	int	x1;

	map_y = 0;
	y1 = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		map_x = 0;
		x1 = 0;
		while (vars->win_w > 0)
		{
			put_image_to_map(vars->map[map_y][map_x], x1, y1, vars);
			vars->win_w--;
			map_x++;
			x1 += 32;
		}
		vars->win_w = backup_w;
		map_y++;
		vars->win_h--;
		y1 += 32;
	}
}

static void	init_vars(t_vars *vars)
{
	vars->collect = 0;
	vars->lantern = 0;
	vars->there_was_lantern = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int	i;

	i = 0;
	if (argc != 2)
	{
		perror("ERROR");
		exit(1);
	}
	(void)argv;
	check_file_is_valid(argv[1]);
	vars.map = get_map(argv[1]);
	if (vars.map != NULL)
	{
		check_map_valid(&vars);
		init_vars(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window (vars.mlx,
			       	vars.win_w * 32, vars.win_h * 32, "So-Long");
		render_map(&vars);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_loop(vars.mlx);
	}
	while (vars.map[i] != NULL)
	{
		free(vars.map[i]);
		i++;
	}
	assets_cleaner(&vars);
	return (0);
}
