/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/02/25 17:53:18 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_init(t_all *all)
{
	all->inc_list = NULL;
	all->name = NULL;
	all->comment = NULL;
	all->champ = NULL;
	all->fd = 0;
	all->size = 0;
	ft_record_inc(all);
	ft_record_func(all);
}

void	ft_record_inc(t_all *all)
{
	all->inc[0] = ft_strdup("live");
	all->inc[1] = ft_strdup("ldi");
	all->inc[2] = ft_strdup("sti");
	all->inc[3] = ft_strdup("add");
	all->inc[4] = ft_strdup("sub");
	all->inc[5] = ft_strdup("and");
	all->inc[6] = ft_strdup("or");
	all->inc[7] = ft_strdup("xor");
	all->inc[8] = ft_strdup("zjmp");
	all->inc[9] = ft_strdup("ld");
	all->inc[10] = ft_strdup("st");
	all->inc[11] = ft_strdup("fork");
	all->inc[12] = ft_strdup("lldi");
	all->inc[13] = ft_strdup("lld");
	all->inc[14] = ft_strdup("lfork");
	all->inc[15] = ft_strdup("aff");
	all->inc[16] = NULL;
}

void	ft_record_func(t_all *all)
{
	all->op[0] = &live;
	all->op[1] = &ldi;
	all->op[2] = &sti;
	all->op[3] = &add;
	all->op[4] = &sub;
	all->op[5] = &and;
	all->op[6] = &or;
	all->op[7] = &xor;
	all->op[8] = &zjmp;
	all->op[9] = &ld;
	all->op[10] = &st;
	all->op[11] = &forki;
	all->op[12] = &lldi;
	all->op[13] = &lld;
	all->op[14] = &lfork;
	all->op[15] = &aff;
}
