#include "corewar.h"

/*void	bebug(t_crwr *crwr, t_cursor *temp)
{
	int		num;

	if (temp->nc == 0)
	{
		num = ~get_direct(crwr->arena->field, looped(temp->pc, 1), 1) + 1;
		printf("P % 4u | live %u", temp->id &0x7ffffff, num);
	}
	else if (temp->nc == 11)
	{
		num = get_direct(crwr->arena->field, looped(temp->pc, 1), 0);
		printf("P % 4u | fork %u", temp->id &0x7ffffff, ~get_direct(crwr->arena->field, looped(temp->pc, 1), 1) + 1);
	}
}
*/
