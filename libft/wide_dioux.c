/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_dioux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:34:22 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:47:43 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wide_diouxx(t_print *info, char c)
{
	char	*join;
	int		a;

	a = ft_find_sharp(info, c);
	join = ft_memalloc(1);
	if ((*info).beforepoint > (*info).afterpoint)
		a = 0;
	if (c == 'p')
		join = ft_join_a_for_p((*info).afterpoint, (*info).str1, join, a);
	else if (!(((*info).nullpoint == 0 && (*info).str1[0] == '0')))
		join = ft_join_a((*info).afterpoint, (*info).str1, join, a);
	join = ft_join_b(info, join);
	ft_strdel(&(info->str1));
	return (join);
}

char	*ft_join_a(int afterpoint, char *str1, char *join, int a)
{
	char	*temp;
	int		k;

	k = (int)ft_strlen(str1);
	if (afterpoint != 0 && afterpoint > k)
	{
		temp = ft_memalloc(afterpoint - k + 1 + a);
		temp = ft_memset(temp, '0', afterpoint - k + a);
		ft_strdel(&join);
		join = ft_strjoin(temp, str1);
		ft_strdel(&temp);
	}
	return (join);
}

char	*ft_join_a_for_p(int afterpoint, char *str1, char *join, int a)
{
	char	*temp;
	int		i;
	int		k;

	k = (int)ft_strlen(str1);
	ft_strdel(&join);
	if (afterpoint != 0 && afterpoint > k)
	{
		temp = ft_memalloc(afterpoint + 2 - k + 1 + a);
		temp = ft_memset(temp, '0', afterpoint + 2 - k + a);
		join = ft_strjoin(temp, str1);
		ft_strdel(&temp);
		if (join[1] == '0')
		{
			join[1] = 'x';
			i = 2;
			while (join[i] != 'x')
				i++;
			join[i] = '0';
		}
	}
	else
		return (ft_strdup(str1));
	return (join);
}

char	*ft_join_b_junior(t_print *info, char *join, int k)
{
	int		i;
	char	*temp;
	char	*test;

	i = (*info).afterpoint > k ? (*info).beforepoint -
		(*info).afterpoint : (*info).beforepoint - k;
	temp = ft_memalloc(i + 1);
	temp = ft_memset(temp, ' ', i);
	if ((*info).afterpoint <= k)
	{
		ft_strdel(&join);
		join = ft_strjoin(temp, (*info).str1);
	}
	else
	{
		test = ft_strjoin(temp, join);
		ft_strdel(&join);
		join = test;
	}
	ft_strdel(&temp);
	return (join);
}

char	*ft_join_b(t_print *info, char *join)
{
	int		k;

	if (info->nullpoint == 0 && info->str1[0] == '0')
		(*info).str1[0] = '\0';
	k = (int)ft_strlen((*info).str1);
	if (info->beforepoint > info->afterpoint && info->beforepoint > k)
		join = ft_join_b_junior(info, join, k);
	else if (join[0] == '\0')
	{
		ft_strdel(&join);
		join = ft_strdup((*info).str1);
	}
	return (join);
}
