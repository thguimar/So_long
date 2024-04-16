/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:22:38 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/16 23:22:20 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	size;
	char			*ptr;
	int				i;

	size = ft_strlen(s1);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_message_error(t_vars *vars, int assets)
{
	write(1, "ERROR\n", 7);
	final_cleaner(vars, assets);
	exit(1);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	**get_map(char *fmap, t_vars *vars)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		ft_message_error(vars, 0);
	all_lines = nengue(fd, line, all_lines);
	close(fd);
	if (!all_lines)
		ft_message_error(vars, 0);
	return (ft_split(all_lines, '\n'));
}

void	get_player(t_vars *vars)
{
	int	map_y;
	int	backup_w;
	int	map_x;

	map_y = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		map_x = 0;
		while (vars->win_w > 0)
		{
			if (vars->map[map_y][map_x] == 'P')
			{
				vars->x_p = map_x;
				vars->y_p = map_y;
			}
			vars->win_w--;
			map_x++;
		}
		vars->win_w = backup_w;
		map_y++;
		vars->win_h--;
	}
	init_vars(vars);
}
