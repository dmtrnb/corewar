/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:24:00 by mkami             #+#    #+#             */
/*   Updated: 2019/07/31 17:47:23 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_null(char *str)
{
	int i;

	i = 0;
	if (str[i] == '0')
		return (1);
	else
		while (str[i] != '\0')
		{
			if (str[i] == '0' && !(str[i - 1] > 48 && str[i] < 58)
					&& str[i - 1] != '.')
				return (1);
			i++;
		}
	return (0);
}

void	ft_print_null(t_print *info)
{
	int i;

	i = 0;
	if (info->null == 0)
		return ;
	while (info->str1[i] != '\0')
	{
		if (info->str1[i] == ' ')
			info->str1[i] = '0';
		else if (info->str1[i] == '-')
		{
			info->str1[i] = '0';
			info->str1[0] = '-';
		}
		i++;
	}
}

char	*ft_not_only_null(char *str1, int plus)
{
	char	*spec;
	char	*temp;

	spec = ft_memalloc(2);
	spec[0] = plus;
	temp = ft_strjoin(spec, str1);
	ft_strdel(&spec);
	ft_strdel(&str1);
	return (temp);
}
