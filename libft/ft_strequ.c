/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:52:18 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/08 13:19:07 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			a = s1[i];
			b = s2[i];
			if (a != b)
				return (0);
			else
				i++;
		}
		return (1);
	}
	return (0);
}
