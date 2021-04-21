/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:48:56 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_search_label(t_line *temp, char *arg, int size)
{
	int		i;
	char	*new;
	char	*temp1;

	i = ft_search_label2(temp, arg);
	if (i == -1)
		ft_error(ERR_LBL_EXI, NULL);
	new = i < 0 ? ft_negative(i, size) : ft_convert(i, 16, size);
	temp1 = ft_add_null(new, size * 2);
	temp->ans = ft_strcat(temp->ans, temp1);
	ft_strdel(&temp1);
}

int		ft_search_label2(t_line *temp, char *arg)
{
	int			sum;

	sum = ft_search_label_forward(temp, arg);
	if (sum == -1)
		sum = ft_search_label_back(temp, arg);
	else
		return (sum);
	return (sum);
}

int		ft_search_label_forward(t_line *temp, char *arg)
{
	t_line		*buf;
	int			i;
	int			sum;

	buf = temp;
	sum = 0;
	while (buf != NULL)
	{
		if (buf->metka != NULL)
		{
			i = 0;
			while (buf->metka[i] != NULL)
			{
				if (ft_strequ(buf->metka[i], arg + 1) == 1)
					return (sum);
				i++;
			}
		}
		sum += buf->size;
		buf = buf->next;
	}
	return (-1);
}

int		ft_search_label_back(t_line *temp, char *arg)
{
	t_line		*buf;
	int			i;
	int			sum;

	buf = temp;
	sum = -buf->size;
	while (buf != NULL)
	{
		if (buf->metka != NULL)
		{
			i = 0;
			while (buf->metka[i] != NULL)
			{
				if (ft_strequ(buf->metka[i], arg + 1) == 1)
				{
					sum += buf->size;
					return (-1 * sum);
				}
				i++;
			}
		}
		sum += buf->size;
		buf = buf->prev;
	}
	return (-1);
}
