/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:28:27 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/03 14:54:03 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	pri(t_cursor *cursor)
{
	t_cursor	*temp;

	if (!cursor)
		return ;
    printf("cursors: ");
	temp = cursor;
	while (temp->next)
	{
        printf("%u ", temp->id & 0x7ffffff);
        printf("%u ", temp->pc);
//        printf("%u ", (temp->id >> 27) & 0xf);
		temp = temp->next;
	}
//    printf("%u ", (temp->id >> 27) & 0xf);
	printf("%u ", temp->id & 0x7ffffff);
    printf("%u ", temp->pc);
	while (temp->prev)
	{
        printf("%u ", temp->id & 0x7ffffff);
        printf("%u ", temp->pc);
//        printf("%u ", (temp->id >> 27) & 0xf);
		temp = temp->prev;
	}
    printf("%u ", temp->id & 0x7ffffff);
    printf("%u ", temp->pc);
//	printf("%u ", (temp->id >> 27) & 0xf);
	printf("\n");
}

void    pr(t_crwr *crwr)
{
    t_players    *temp;
    
    temp = crwr->players;
    while (temp)
    {
        printf("id:%d\n%s\n%s\n%s\nsize:%u\n", temp->id, temp->filename, temp->name, temp->comment, temp->code_size);
        size_t        i = 0;
        while (i != temp->code_size)
        {
            if (i && !(i % COLUMNS))
                printf("\n");
            printf(" %02x", *((unsigned char *)temp->code + i));
            i++;
        }
        temp = temp->next;
    }
    int i = 1;
/*    t_name    *name = crwr->name;
    
    while (name)
    {
        printf("%d %s\n%s\n", i, name->name, name->comment);
        name = name->next;
        i++;
    }
*/
	int fd = open("0", O_WRONLY | O_CREAT);
	t_cursor    *cursor = crwr->cursor;
    while (cursor)
    {
//        printf("\nid_cur:%d\n\n", cursor->id);
        cursor = cursor->next;
    }
    i = 0;
    while (i != MEM_SIZE)
    {
        if (i && !(i % COLUMNS))
            dprintf(fd, "\n");
        dprintf(fd, " %02x", *((unsigned char *)crwr->arena->field + i));
        i++;
    }
	dprintf(fd, "\n");
	close(fd);
//	printf("\nalive: %d\nnbr_live: %u\ncycles_without_check: %u\ncycles_to_die: %u\nnbr_check: %u\n", crwr->arena->alive, crwr->arena->nbr_live, crwr->arena->cycles_without_check, crwr->arena->cycles_to_die, crwr->arena->nbr_check);
}

int        ft_error(char *line, int i)
{
    printf(ANSI_COLOR_RED"%s"ANSI_COLOR_RESET"\n", line);    //ft_putstr(line);
    exit(i == -1 ? i : -1);
}

//void    free_all(t_crwr **crwr)
