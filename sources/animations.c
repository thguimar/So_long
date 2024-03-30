/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:10:44 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/30 16:30:50 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "so_long.h"

void	render_img(t_vars **vars)
{
	int			img_w;
	int			img_h;

	(*vars)->e_vars.imgs[0] = "./img/1.xpm";
	(*vars)->e_vars.imgs[1] = "./img/2.xpm";
	(*vars)->e_vars.imgs[2] = "./img/1.xpm";
	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx, "./img/ground.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx, (*vars)->win, (*vars)->img,
		(*vars)->e_vars.x_e * 32, (*vars)->e_vars.y_e * 32);
	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx, (*vars)->e_vars.imgs[(*vars)->e_vars.x],
			&img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx, (*vars)->win, (*vars)->img,
		(*vars)->e_vars.x_e * 32, (*vars)->e_vars.y_e * 32);
}

void    move_enemy(t_vars **vars)
{
	int img_w;
	int img_h;
    
	(*vars)->img = mlx_xpm_file_to_image((*vars)->mlx, "./assets/enemy.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->img, (*vars)->e_vars.x_e * 32, (*vars)->e_vars.y_e * 32);
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 0)
			(*vars)->e_vars.x_e++;
	else
		(*vars)->e_vars.path_to_move = 1;
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 0)
			(*vars)->e_vars.x_e--;
	else
		(*vars)->e_vars.path_to_move = 0;

        
}

static void ft_lose(t_vars **v, char *err)
{
    int x;

    x = 0;
    while(v->map[x])
    {
        free(v->map[x]);
        x++;
    }
    free(v->map);
    printf("%s", err);
    exit(0);
}

int animation(t_vars *vars)
{
    if (get_position_for_enemy(&vars) != 0)
    {
        if (vars->e_vars.sleep-- <= 0)
        {
            vars->e_vars.x++;
            vars->e_vars.sleep = 5;
        }
        if (vars->e_vars.x == 3)
            vars->e_vars.x = 0;
        if (vars->e_vars.sleep_for_move -- <= 0)
        {
            move_enemy(&vars);
            vars->e_vars.sleep_for_move = 30;
        }
        if ((vars->e_vars.y_e == vars->y_p / 32) && (vars->e_vars.x_e == vars->x_p / 32))
            ft_lose(&vars, "GAME OVER");
        render_img(&vars);
    }
    return (0);
}
*/