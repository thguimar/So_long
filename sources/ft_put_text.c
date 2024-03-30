/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:34:47 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/28 19:42:49 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_text(t_vars *v)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(v)->movement);
	text = ft_join_strings("Move: ", number);
	v->img = mlx_xpm_file_to_image(
			v->mlx, "./img/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.wall->img, 0, 0);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.wall->img, 32, 0);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets.wall->img, 32 * 2, 0);
	mlx_string_put(v->mlx, v->win, 5, 10, 0xfffffff, text);
	printf("%s\n", number);
	free(text);
	free(number);
}
