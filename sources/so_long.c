/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:24:07 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/16 23:26:59 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
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
		final_cleaner(vars, 1);
		exit(1);
	}
	return (0);
}

int	ft_exit(t_vars *v)
{
	final_cleaner(v, 1);
	exit(1);
	return (0);
}

void	render_map(t_vars *vars, char **argv)
{
	int	map_y;
	int	y1;
	int	backup_w;

	map_y = 0;
	y1 = 0;
	backup_w = vars->win_w;
	flood_checker(vars, argv);
	while (vars->win_h > 0)
	{
		map_xloop(vars, 0, y1, map_y);
		vars->win_w = backup_w;
		map_y++;
		vars->win_h--;
		y1 = (map_y * 32);
	}
}

void	init_vars(t_vars *vars)
{
	vars->collect = 0;
	vars->lantern = 0;
	vars->there_was_lantern = 0;
	vars->movement = 0;
	if (vars->map[0] == NULL)
	{
		write(1, "ERROR, no map\n", 14);
		final_cleaner(vars, 0);
		exit (1);
	}
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	check_file_is_valid(argv[1]);
	vars.map = get_map(argv[1], &vars);
	if (vars.map != NULL)
	{
		init_vars(&vars);
		check_map_valid(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window (vars.mlx,
				vars.win_w * 32, vars.win_h * 32, "So-Long");
		render_map(&vars, argv);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_loop(vars.mlx);
	}
	return (final_cleaner (&vars, 1), 0);
}
