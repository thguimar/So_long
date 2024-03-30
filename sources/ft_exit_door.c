/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:00:04 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/28 20:26:37 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    exit_door(t_vars *v)
{
    int x;

    x = 0;
    while (v->map[x])
    {
        free(v->map[x]);
        x++;
    }
    free(v->map);
    assets_cleaner(v);
    mlx_destroy_window(v->mlx, v->win);
    exit(1);
}
