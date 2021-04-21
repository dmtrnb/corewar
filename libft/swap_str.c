/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:08:58 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:47:33 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_minus(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	ft_swap_str(t_print *info)
{
	int		i;
	int		k;
	char	*temp;
	char	*old;

	i = 0;
	while (info->str1[i] != '\0')
	{
		if (info->str1[i] != ' ')
			break ;
		i++;
	}
	if (i == 0 || info->minus == 0)
		return ;
	old = info->str1;
	k = ft_strlen(info->str1);
	temp = (char *)malloc((sizeof(temp) * (k + 1)));
	temp = ft_memset(temp, '\0', k + 1);
	temp = ft_strncpy(temp, (info->str1 + i), k - i);
	temp = ft_strncat(temp, info->str1, i);
	info->str1 = temp;
	ft_strdel(&old);
}

void	ft_glue_space(t_print *info)
{
	char *temp;

	if (info->space == 1 && info->plus == 0 &&
			((info->str[info->len] == 'd' || info->str[info->len] == 'i' ||
			info->str[info->len] == 'D')))
	{
		temp = info->str1;
		info->str1 = ft_strjoin(" ", temp);
		ft_strdel(&temp);
	}
}
