/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:42:44 by psong             #+#    #+#             */
/*   Updated: 2021/02/01 19:26:30 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_malloc_error(char **dst)
{
	unsigned int	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (NULL);
}

int		ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	**ft_size_words(const char *s, char c, char **dst, int i)
{
	int	j;
	int	size_word;

	j = 0;
	while (s[i])
	{
		size_word = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				size_word++;
				i++;
			}
			dst[j] = malloc(sizeof(char) * (size_word + 1));
			if (!(&dst[j]))
				return (NULL);
			j++;
		}
		else
			i++;
	}
	return (dst);
}

void	ft_do(const char *s, char **dst, char c, int i)
{
	int	k;
	int	j;

	j = 0;
	while (s[i])
	{
		k = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				dst[j][k++] = s[i++];
			dst[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	dst[j] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**dst;

	if (s == NULL)
		return (NULL);
	if (!(dst = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	if (!(ft_size_words(s, c, dst, 0)))
		return (ft_malloc_error(dst));
	ft_do(s, dst, c, 0);
	return (dst);
}
