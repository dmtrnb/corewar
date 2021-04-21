/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:23:13 by mkami             #+#    #+#             */
/*   Updated: 2019/07/31 17:47:03 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsrt(char const *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c == '^' && str[i + 1] == '@')
		{
			c = 0;
			i++;
		}
		write(1, &c, 1);
		i++;
	}
}

char	*ft_wide_f(t_print *info)
{
	char	*temp;
	char	*pemp;
	int		k;

	k = (int)ft_strlen(info->str1);
	if (info->beforepoint > k)
	{
		temp = ft_memalloc(info->beforepoint - k + 1);
		temp = ft_memset(temp, ' ', info->beforepoint - k);
		pemp = ft_strjoin(temp, info->str1);
		ft_strdel(&temp);
		ft_strdel(&info->str1);
		return (pemp);
	}
	return (info->str1);
}

char	*ft_star_helper(char *str, char *temp, long long int a)
{
	char	*num;
	char	*helper;
	int		i;

	i = 0;
	num = ft_itoa(a);
	helper = (char *)malloc(sizeof(char) *
		(ft_strlen(str) + ft_strlen(num)) + 1);
	while (str[i] != '*')
	{
		helper[i] = str[i];
		i++;
	}
	helper = ft_strcat(helper, num);
	if (str[i + 1] >= 48 && str[i + 1] <= 57)
		helper[ft_strlen(helper)] = ' ';
	helper = ft_strcat(helper, temp + 1);
	ft_strdel(&str);
	ft_strdel(&num);
	return (helper);
}

char	*ft_make_star2(t_print *info, char *str, va_list hello)
{
	int						index;
	char					*temp;
	long long int			a;
	char					*point;

	index = 0;
	while (index < 2 && (temp = ft_strchr(str, '*')) != NULL)
	{
		info->star = 1;
		point = ft_strchr(str, '.');
		a = va_arg(hello, int);
		if (a < 0 && point != NULL && point[1] == '*')
			a = 0;
		else if (a == 0)
			info->star = 0;
		str = ft_star_helper(str, temp, a);
		index++;
	}
	return (str);
}
