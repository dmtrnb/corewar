/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkami <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:32:08 by mkami             #+#    #+#             */
/*   Updated: 2020/03/07 19:35:58 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_sum(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			k++;
		}
		else
			while (str[i] == c || str[i] == '\t')
				i++;
	}
	return (k);
}

static void		del(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static int		slovo(char **s, char const *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] != c)
		{
			while (str[i] != c && str[i++] != '\0')
				j++;
			if (!(s[k] = (char*)malloc(sizeof(char) * (j + 1))))
			{
				del(s, k);
				return (0);
			}
			k++;
		}
		else
			while (str[i] == c || str[i] == '\t')
				i++;
	}
	return (1);
}

static void		record(char **s, char const *str, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = -1;
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
				s[k][++j] = str[i++];
			s[k][++j] = '\0';
			k++;
		}
		else
			while (str[i] == c || str[i] == '\t')
				i++;
	}
	s[k] = 0;
}

char			**ft_strsplit_wide2(char const *str, char c)
{
	int		sum;
	char	**s;

	if (!(str))
		return (NULL);
	sum = ft_sum(str, c);
	s = (char**)malloc(sizeof(char *) * (sum + 1));
	if (!(s))
		return (NULL);
	if (!(slovo(s, str, c)))
		return (NULL);
	record(s, str, c);
	return (s);
}
