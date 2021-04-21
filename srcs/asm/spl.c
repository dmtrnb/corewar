/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:04:00 by mkami             #+#    #+#             */
/*   Updated: 2020/02/25 18:50:39 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	words(char const *st, char c)
{
	int		i;
	int		w;
	char	*s;

	s = (char *)st;
	i = 0;
	w = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			w++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		while (s[i] == c)
			i++;
	}
	return (w);
}

static int	wordlen(char const *s, char c, int word)
{
	int i;
	int w;
	int len;

	i = 0;
	w = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (w == word)
				len++;
		}
		if (w == word)
			return (len);
		w++;
	}
	return (0);
}

static int	refresh(char **p, int size, int i)
{
	int k;

	k = 0;
	p[i] = (char *)malloc((sizeof(**p) * (size + 1)));
	if (p[i] == NULL)
	{
		while (k <= i)
		{
			free(p[k]);
			k++;
		}
		free(p);
		return (0);
	}
	return (1);
}

char		**ft_strsplit_wide(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		k;

	if (s == NULL
			|| (p = (char **)malloc((sizeof(*p) * (words(s, c) + 1)))) == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < words(s, c))
	{
		j = -1;
		if (refresh(p, wordlen(s, c, i), i) == 0)
			return (NULL);
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k] != '\0')
			p[i][++j] = s[k++];
		p[i][++j] = '\0';
		i++;
	}
	p[i] = 0;
	return (p);
}
