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
	vars->e_vars.sign = 1;
	vars->e_vars.x = 0;
	vars->e_vars.sleep = 5;
	vars->e_vars.sleep_for_move = 60;
	vars->e_vars.path_to_move = 0;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		perror("ERROR");
		exit(1);
	}
	(void)argv;
	//checkar se o file e valido com argv[1]
	check_file_is_valid(argv[1]);
	/*atribuir mapa a "vars.map"*/
	vars.map = get_map(argv[1]);
	//se vars.map diferente de nulo
	if (vars.map != NULL)
	{
	//	checkar validade do mapa;
		check_map_valid(&vars);
	//	inicializar variaveis;
		init_vars(&vars);
	//	mlx_init
		vars.mlx = mlx_init();
	//	mlx_new_window
		vars.win = mlx_new_window (vars.mlx,
			       	vars.win_w * 32, vars.win_h * 32, "So-Long");
	//	renderizar mapa
		render_map(&vars);
	//	mlx_hook
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
	//	mlx_loop_hook(vars.mlx, animation, &vars);
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
	//	mlx_hook
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
	//	mlx_string_put
	//	mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
	//	mlx_loop_hook
	//	mlx_loop_hook(vars.mlx, animation, &vars);
	//	mlx_loop
		mlx_loop(vars.mlx);
	}
	return (0);
}
