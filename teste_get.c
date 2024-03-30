/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:35:13 by thguimar          #+#    #+#             */
/*   Updated: 2024/03/04 15:36:47 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	printf("teste");
	char *line;
	int fd;

	fd = open("teste_get.c", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
