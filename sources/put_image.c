/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:23 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/12 19:36:59 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_cleaner(t_vars *v)
{
	mlx_destroy_image(v->mlx, v->assets->character->img);
	free(v->assets->character);
	mlx_destroy_image(v->mlx, v->assets->ground->img);
	free(v->assets->ground);
	mlx_destroy_image(v->mlx, v->assets->lantern->img);
	free(v->assets->lantern);
	mlx_destroy_image(v->mlx, v->assets->character_left->img);	
	free(v->assets->character_left);
	mlx_destroy_image(v->mlx, v->assets->ground_with_character_left->img);
	free(v->assets->ground_with_character_left);
	mlx_destroy_image(v->mlx, v->assets->ground_with_character->img);
	free(v->assets->ground_with_character);
	mlx_destroy_image(v->mlx, v->assets->character_with_lantern->img);
	free(v->assets->character_with_lantern);
	mlx_destroy_image(v->mlx, v->assets->character_with_lantern2->img);
	free(v->assets->character_with_lantern2);
	mlx_destroy_image(v->mlx, v->assets->door->img);
	free(v->assets->door);
	mlx_destroy_image(v->mlx, v->assets->ground_with_lantern->img);
	free(v->assets->ground_with_lantern);
	mlx_destroy_image(v->mlx, v->assets->parchment->img);
	free(v->assets->parchment);
	mlx_destroy_image(v->mlx, v->assets->ground_with_parchment->img);
	free(v->assets->ground_with_parchment);
	mlx_destroy_image(v->mlx, v->assets->wall->img);
	free(v->assets->wall);
	mlx_destroy_image(v->mlx, v->assets->ground_with_door->img);
	free (v->assets->ground_with_door);
	mlx_destroy_image(v->mlx, v->assets->ground_with_character_with_lantern->img);
	free(v->assets->ground_with_character_with_lantern);
	mlx_destroy_image(v->mlx, v->assets->ground_with_character_with_lantern2->img);
	free(v->assets->ground_with_character_with_lantern2);
	/*mlx_destroy_image(v->mlx, v->img);
	free(v->img);*/
	free(v->assets);
}

void	assets_initiator(t_vars *v)
{
	v->assets->character = new_file_img("Assets/character.xpm", v->mlx, v->win);
	v->assets->ground = new_file_img("Assets/ground.xpm", v->mlx, v->win);
	v->assets->lantern = new_file_img("Assets/lantern.xpm", v->mlx, v->win);
	v->assets->character_left = new_file_img("Assets/character_left.xpm", v->mlx, v->win);
	v->assets->ground_with_character_left = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->ground_with_character_left, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->ground_with_character_left, v->assets->character_left, 0, 0);
	v->assets->ground_with_character = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->ground_with_character, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->ground_with_character, v->assets->character, 0, 0);
	v->assets->character_with_lantern = new_file_img("Assets/character_lantern.xpm", v->mlx, v->win);
	v->assets->character_with_lantern2 = new_file_img("Assets/character_lantern2.xpm", v->mlx, v->win);
	v->assets->door = new_file_img("Assets/door.xpm", v->mlx, v->win);
	v->assets->ground_with_lantern = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->ground_with_lantern, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->ground_with_lantern, v->assets->lantern, 0, 0);
	v->assets->parchment = new_file_img("Assets/parchment.xpm", v->mlx, v->win);
	v->assets->ground_with_parchment = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->ground_with_parchment, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->ground_with_parchment, v->assets->parchment, 0, 0);
	v->assets->wall = new_file_img("Assets/wall.xpm", v->mlx, v->win);
	v->assets->ground_with_door = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->ground_with_door, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->ground_with_door, v->assets->door, 0, 0);
	v->assets->ground_with_character_with_lantern = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->ground_with_character_with_lantern, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->ground_with_character_with_lantern, v->assets->character_with_lantern, 0, 0);
	v->assets->ground_with_character_with_lantern2 = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->ground_with_character_with_lantern2, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->ground_with_character_with_lantern2, v->assets->character_with_lantern2, 0, 0);
}

void    put_image_to_map(char p, int x1, int y1, t_vars *v)
{
        if (p == '1')
            mlx_put_image_to_window(v->mlx, v->win, v->assets->wall->img, x1, y1);
        else if (p == 'C')
        {
             mlx_put_image_to_window(v->mlx, v->win, v->assets->ground_with_parchment->img, x1, y1);
             v->collect++;
        }
        else if (p == 'E')
             mlx_put_image_to_window(v->mlx, v->win, v->assets->ground_with_door->img, x1, y1);
        else if (p == 'P')
        {
            v->y_p = y1;
            v->x_p = x1;
            mlx_put_image_to_window(v->mlx, v->win, v->assets->ground_with_character->img, x1, y1);
        }
        else if (p == 'L')
		{
        	mlx_put_image_to_window(v->mlx, v->win, v->assets->ground_with_lantern->img, x1, y1);
			v->lantern++;
			v->there_was_lantern++;
		}
	else
		mlx_put_image_to_window(v->mlx, v->win, v->assets->ground->img, x1, y1);
}
