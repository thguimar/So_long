/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_put_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:23:54 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/04 17:57:09 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	char			**map;
	int				collect;
//	t_enemy_vars	e_vars;
}	t_vars;

typedef struct s_imgs
{
	char		*addr;
	int			bites_per_pxl;
	int			endian;
	int			height;
	int			line_len;
	int			width;
	void		*win;
	void		*img;
}				t_imgs;


typedef struct s_assets {
	t_imgs	*lantern;
	t_imgs	*ground;
	t_imgs	*character;
	t_imgs	*ground_with_character;
	t_imgs	*character_with_lantern;
	t_imgs	*door;
	t_imgs	*ground_with_lantern;
	t_imgs	*parchment;
	t_imgs	*ground_with_parchment;
	t_imgs	*wall;
	t_imgs	*enemy;
	t_imgs	*ground_with_enemy;
	t_imgs	*ground_with_door;
	t_imgs	*ground_with_character_with_lantern;
}	t_assets;

t_imgs	*new_img(int w, int h, t_vars *mlx, t_vars *window)
{
	t_imgs	*image;

	image = (t_imgs *)malloc(sizeof(t_imgs));
	image->win = window;
	image->img = mlx_new_image(mlx, w, h);
	image->addr = mlx_get_data_addr(image->img, &(image->bites_per_pxl),
			&(image->line_len), &(image->endian));
	image->width = w;
	image->height = h;
	return (image);
}

t_imgs	*new_file_img(char *path, void *mlx, void *window)
{
	t_imgs	*image;

	image = (t_imgs *)malloc(sizeof(t_imgs));
	image->win = window;
	image->img = mlx_xpm_file_to_image(mlx, path, &image->width,
			&image->height);
	if (!image->img)
		write(2, "File could not be read\n", 23);
	else
		image->addr = mlx_get_data_addr(image->img, &(image->bites_per_pxl),
				&(image->line_len), &(image->endian));
	return (image);
}

void	put_pixel_img(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00FFFFFF || color == -16777216)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bites_per_pxl / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_pixel_img(t_imgs *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_len) + (x
				* img->bites_per_pxl / 8))));
}

void	put_img_to_img(t_imgs *dst, t_imgs *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
/*
void	put_image(t_vars ***v, int x, int y, t_assets *assets)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx, (**v)->win, (**v)->img, x, y);
}*/

void	assets_initiator1(t_vars *v, t_assets *assets)
{
	assets->character = new_file_img("Assets/character.xpm", v->mlx, v->win);
	assets->ground = new_file_img("Assets/ground.xpm", v->mlx, v->win);
	assets->lantern = new_file_img("Assets/lantern.xpm", v->mlx, v->win);
	assets->ground_with_character = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(assets->ground_with_character, assets->ground, 0, 0);
	put_img_to_img(assets->ground_with_character, assets->character, 0, 0);
	assets->character_with_lantern = new_file_img("Assets/character_lantern.xpm", v->mlx, v->win);
	assets->door = new_file_img("Assets/door.xpm", v->mlx, v->win);
	assets->ground_with_lantern = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(assets->ground_with_lantern, assets->ground, 0, 0);
	put_img_to_img(assets->ground_with_lantern, assets->lantern, 0, 0);
	assets->parchment = new_file_img("Assets/parchment.xpm", v->mlx, v->win);
	assets->ground_with_parchment = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(assets->ground_with_parchment, assets->ground, 0, 0);
	put_img_to_img(assets->ground_with_parchment, assets->parchment, 0, 0);
//	assets->wall = new_file_img("Assets/wall.xpm", v->mlx, v->win);
//	assets->enemy = new_file_img("Assets/enemy.xpm", v->mlx, v->win);
//	assets->ground_with_enemy = new_img(32, 32, v->mlx, v->win);
//	put_img_to_img(assets->ground_with_enemy, assets->ground, 0, 0);
//	put_img_to_img(assets->ground_with_enemy, assets->enemy, 0, 0);
	assets->ground_with_door = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(assets->ground_with_door, assets->ground, 0, 0);
	put_img_to_img(assets->ground_with_door, assets->door, 0, 0);
	assets->ground_with_character_with_lantern = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(assets->ground_with_character_with_lantern, assets->ground, 0, 0);
	put_img_to_img(assets->ground_with_character_with_lantern, assets->character_with_lantern, 0, 0);
}

void	assets_initiator(t_vars *vars, t_assets *assets)
{
	assets_initiator1(vars, assets);
}

void    put_image_to_map(char p, int x1, int y1, t_vars *v, t_assets *assets)
{
	assets_initiator(v, assets);
        if (p == '1')
                mlx_put_image_to_window(v->mlx, v->win, assets->wall->img, x1, y1);
        else if (p == 'C')
        {
                mlx_put_image_to_window(v->mlx, v->win, assets->ground_with_parchment->img, x1, y1);
                v->collect++;
        }
        else if (p == 'E')
                mlx_put_image_to_window(v->mlx, v->win, assets->ground_with_door->img, x1, y1);
        else if (p == 'P')
        {
                v->y_p = y1;
                v->x_p = x1;
                mlx_put_image_to_window(v->mlx, v->win, assets->ground_with_character->img, x1, y1);
        }
        else if (p == 'L')
        	mlx_put_image_to_window(v->mlx, v->win, assets->ground_with_lantern->img, x1, y1);
		else
			mlx_put_image_to_window(v->mlx, v->win, assets->ground_with_character->img, x1, y1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_assets *assets = NULL;
	
	(void)argc;
	vars.map = &argv[1];
	vars.map = malloc(sizeof(char *) * 70); //=>62 && <=325
	assets = malloc(sizeof(t_assets));
	int	map_y = 400;
	int	map_x = 400;
	int	x = 400;
	int	y = 400;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window (vars.mlx,
			        800, 800, "So-Long");
	put_image_to_map(vars.map[map_y][map_x], x, y, &vars, assets);
	mlx_loop(vars.mlx);
}
