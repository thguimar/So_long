/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:23 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/30 15:34:35 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_cleaner(t_vars *v)
{
	free (v->assets.character);
	free (v->assets.ground);
	free (v->assets.lantern);
	free (v->assets.ground_with_character);
	free (v->assets.character_with_lantern);
	free (v->assets.door);
	free (v->assets.ground_with_lantern);
	free (v->assets.parchment);
	free (v->assets.ground_with_parchment);
	free (v->assets.wall);
	free (v->assets.ground_with_door);
	free (v->assets.ground_with_character_with_lantern);
	free (v->assets.character_left);
	free (v->assets.ground_with_character_left);
}

void	assets_initiator(t_vars *v)
{
	v->assets.character = new_file_img("../Assets/character.xpm", v->mlx, v->win);
	v->assets.ground = new_file_img("../Assets/ground.xpm", v->mlx, v->win);
	v->assets.lantern = new_file_img("../Assets/lantern.xpm", v->mlx, v->win);
	v->assets.character_left = new_file_img("../Assets/character_left.xpm", v->mlx, v->win);
	v->assets.ground_with_character_left = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets.ground_with_character_left, v->assets.ground, 0, 0);
	put_img_to_img(v->assets.ground_with_character_left, v->assets.character_left, 0, 0);
	v->assets.ground_with_character = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets.ground_with_character, v->assets.ground, 0, 0);
	put_img_to_img(v->assets.ground_with_character, v->assets.character, 0, 0);
	v->assets.character_with_lantern = new_file_img("../Assets/character_lantern.xpm", v->mlx, v->win);
	v->assets.character_with_lantern2 = new_file_img("../Assets/character_lantern2.xpm", v->mlx, v->win);
	v->assets.door = new_file_img("../Assets/door.xpm", v->mlx, v->win);
	v->assets.ground_with_lantern = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets.ground_with_lantern, v->assets.ground, 0, 0);
	put_img_to_img(v->assets.ground_with_lantern, v->assets.lantern, 0, 0);
	v->assets.parchment = new_file_img("../Assets/parchment.xpm", v->mlx, v->win);
	v->assets.ground_with_parchment = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets.ground_with_parchment, v->assets.ground, 0, 0);
	put_img_to_img(v->assets.ground_with_parchment, v->assets.parchment, 0, 0);
	v->assets.wall = new_file_img("../Assets/wall.xpm", v->mlx, v->win);
//	assets->enemy = new_file_img("../Assets/enemy.xpm", v->mlx, v->win);
//	assets->ground_with_enemy = new_img(32, 32, v->mlx, v->win);
//	put_img_to_img(assets->ground_with_enemy, assets->ground, 0, 0);
//	put_img_to_img(assets->ground_with_enemy, assets->enemy, 0, 0);
	v->assets.ground_with_door = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets.ground_with_door, v->assets.ground, 0, 0);
	put_img_to_img(v->assets.ground_with_door, v->assets.door, 0, 0);
	v->assets.ground_with_character_with_lantern = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets.ground_with_character_with_lantern, v->assets.ground, 0, 0);
	put_img_to_img(v->assets.ground_with_character_with_lantern, v->assets.character_with_lantern, 0, 0);
	v->assets.ground_with_character_with_lantern2 = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets.ground_with_character_with_lantern2, v->assets.ground, 0, 0);
	put_img_to_img(v->assets.ground_with_character_with_lantern2, v->assets.character_with_lantern2, 0, 0);
}

void    put_image_to_map(char p, int x1, int y1, t_vars *v)
{
	assets_initiator(v);
        if (p == '1')
            mlx_put_image_to_window(v->mlx, v->win, v->assets.wall->img, x1, y1);
        else if (p == 'C')
        {
             mlx_put_image_to_window(v->mlx, v->win, v->assets.ground_with_parchment->img, x1, y1);
             v->collect++;
        }
        else if (p == 'E')
             mlx_put_image_to_window(v->mlx, v->win, v->assets.ground_with_door->img, x1, y1);
        else if (p == 'P')
        {
            v->y_p = y1;
            v->x_p = x1;
            mlx_put_image_to_window(v->mlx, v->win, v->assets.ground_with_character->img, x1, y1);
        }
        else if (p == 'L')
		{
        	mlx_put_image_to_window(v->mlx, v->win, v->assets.ground_with_lantern->img, x1, y1);
			v->lantern++;
			v->there_was_lantern++;
		}
	else
		mlx_put_image_to_window(v->mlx, v->win, v->assets.ground->img, x1, y1);
}
