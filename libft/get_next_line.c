/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:33:57 by dholiday          #+#    #+#             */
/*   Updated: 2019/11/04 21:39:47 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chit(int fd, void **str)
{
	int		i;
	void	*new;
	char	buf[BUFF_SIZE + 1];

	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		new = *str;
		*str = ft_strjoin(new, buf);
		free(new);
		if (*str == NULL)
			return (-1);
		if (ft_strchr(*str, '\n') != NULL)
			break ;
	}
	if (i == -1)
		return (-1);
	return (0);
}

void	ft_record(t_list *a, int *f, int fd, char **line)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	*f = ft_chit(fd, &(a->content));
	if (*f == -1)
		return ;
	*f = ((char*)a->content)[0] == '\0' ? 0 : 1;
	while (((char*)a->content)[i] != '\n' && ((char*)a->content)[i] != '\0')
		i++;
	*line = ft_strsub(a->content, 0, i);
	len = ft_strlen(a->content);
	if (*line == NULL)
	{
		*f = -1;
		return ;
	}
	new = (char*)a->content;
	if (i == len)
	{
		((char*)a->content)[0] = '\0';
	}
	else
		a->content = ft_memmove(new, new + i + 1, len - i);
}

t_list	*ft_list(t_list *new, int fd)
{
	if (new != NULL)
	{
		while (new->next != NULL)
			if ((int)new->content_size == fd)
				break ;
			else
				new = new->next;
		if (new->next == NULL && (int)new->content_size != fd)
		{
			new->next = ft_lstnew((void*)"", 1);
			new = new->next;
			new->content_size = fd;
		}
	}
	else
	{
		new = ft_lstnew((void*)"", 1);
		new->content_size = fd;
	}
	return (new);
}

int		get_next_line(const	int fd, char **line)
{
	static t_list	*new;
	t_list			*a;
	int				f;
	char			*check;

	check = NULL;
	f = 0;
	if (fd < 0 || BUFF_SIZE == 0 || line == NULL || read(fd, check, 0) < 0)
		return (-1);
	a = new;
	new = ft_list(new, fd);
	ft_record(new, &f, fd, line);
	if (a != NULL)
		new = a;
	return (f);
}
