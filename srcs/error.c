/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:28:27 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/27 18:46:42 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    say_hello(t_players *players)
{
    t_players    *temp;
    
    printf("Introducing contestants...\n");    //    FT
    temp = players;
    while (temp)
    {
        printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n", temp->id, temp->code_size, temp->name, temp->comment);    //    FT
        temp = temp->next;
    }
}

/*void    say_buy(const )
 {
 while (temp)
 {
 temp = crwr->players;
 if (crwr->arena->alive == list->id)
 {
 printf("Contestant %zu, \"%s\", has won !\n", temp->id, temp->name);
 break ;
 }
 list = list->next;
 }
 }
 */
void	pri(t_cursor *cursor)
{
	t_cursor	*temp;

	temp = cursor;
	while (temp->next)
	{
		printf("%u ", (temp->id >> 27) & 0xf);
		temp = temp->next;
	}
	printf("%u ", (temp->id >> 27) & 0xf);
	while (temp->prev)
	{
		printf("%u ", (temp->id >> 27) & 0xf);
		temp = temp->prev;
	}
	printf("%u ", (temp->id >> 27) & 0xf);
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
    t_name    *name = crwr->name;
    
    int i = 1;
    while (name)
    {
        printf("%d %s\n%s\n", i, name->name, name->comment);
        name = name->next;
        i++;
    }
    t_cursor    *cursor = crwr->cursor;
    while (cursor)
    {
        printf("\nid_cur:%d\n\n", cursor->id);
        cursor = cursor->next;
    }
    i = 0;
    while (i != MEM_SIZE)
    {
        if (i && !(i % COLUMNS))
            printf("\n");
        printf(" %02x", *((unsigned char *)crwr->arena->field + i));
        i++;
    }
}

int        ft_error(char *line, int i)
{
    printf(ANSI_COLOR_RED"%s"ANSI_COLOR_RESET"\n", line);    //ft_putstr(line);
    exit(i);
}

//void    free_all(t_crwr **crwr)
