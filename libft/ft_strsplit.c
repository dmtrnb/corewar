/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:52:18 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/07 19:25:16 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			s[k] = (char*)malloc(sizeof(char) * (j + 1));
			if (!(s[k]))
			{
				del(s, k);
				return (0);
			}
			k++;
		}
		else
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
			i++;
	}
	s[k] = 0;
}

char			**ft_strsplit(char const *str, char c)
{
	int		sum;
	char	**s;

	if (!(str))
		return (NULL);
	sum = ft_sum_w(str, c);
	s = (char**)malloc(sizeof(char *) * (sum + 1));
	if (!(s))
		return (NULL);
	if (!(slovo(s, str, c)))
		return (NULL);
	record(s, str, c);
	return (s);
}
