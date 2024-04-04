/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:30:55 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/04 17:25:28 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cpy(char *dst, char const *src, int n)
{
	while (n--)
		*dst++ = *src++;
	*dst = '\0';
}

static int	allocate2(char const *s, char **list, int word_length, int index)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (word_length + 1));
	if (!word)
	{
		while (index >= 0)
			free(list[index--]);
		free(list);
		return (0);
	}
	cpy(word, (s - word_length), word_length);
	list[index++] = word;
	return (1);
}

static int	create_word(char const *s, char c, char **list, int words)
{
	int		word_length;
	int		index;

	index = 0;
	while (*s != '\0')
	{
		word_length = 0;
		if (*s != c)
		{
			while (index != words)
			{
				if (*s == c || *s == '\0')
				{
					if (!allocate2(s, list, word_length, index))
						return (0);
					index++;
					break ;
				}
				word_length++;
				s++;
			}
		}
		s++;
	}
	return (index);
}

static int	count_words(char const *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			words++;
		str++;
	}
	return (words);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**list;
	int		index;

	if (s == 0 || !s)
		return (0);
	words = count_words(s, c);
	list = malloc(sizeof(char *) * (words + 1));
	if (!list)
		return (NULL);
	index = create_word(s, c, list, words);
	if (!list)
		return (NULL);
	list[index] = NULL;
	free(s);
	return (list);
}
