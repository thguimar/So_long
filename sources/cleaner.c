/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:23:27 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/11 17:08:44 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void final_cleaner(t_vars *vars, int assets)
{
    int i;

    i = 0;
    while (vars->map && vars->map[i] != NULL)
	{
	    free(vars->map[i]);
	    i++;
    }
    free(vars->map);
    if (assets == 1)
    {
        assets_cleaner(vars);
        mlx_destroy_window(vars->mlx, vars->win);
        free(vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
}
