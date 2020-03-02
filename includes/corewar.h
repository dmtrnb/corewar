#include "op.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>

#define OPT_DUMP "-d"
#define OPT_N "-n"
#define OPT_V "-v"
#define OPT_A "-a"

#define ERR_USG "usage"
#define ERR_NBR_PL "wrong nbr_pl"

#define SIZE_MAGIC_NULL 4
#define COLUMNS 64

#define MAX_COLOR_PL 4

#define CYCLE_BURN 50

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct		s_visu	{
    char			count;
    char            cycle;
	unsigned		pc;
	struct s_visu	*next;
}					t_visu;

typedef struct		s_name	{
	char			*name;
	char			*comment;
	unsigned		code_size;
	struct s_name	*next;
}					t_name;

typedef struct        s_player    {
	char			id;
	char			*filename;
	char			*name;
	char			*comment;
	unsigned		code_size;
	void			*code;
	struct s_player	*next;
}					t_players;

typedef struct		s_arena	{
	char			alive;
    unsigned        nbr_live;
	unsigned   		cycles;
    unsigned		cycles_without_check;
	int		cycles_to_die;
	unsigned		nbr_check;
    void            *field;
    void            *par_field;
    t_visu          *visu;
}					t_arena;

typedef struct		s_cursor	{
    unsigned		id;
	unsigned		pc;
	unsigned char	nc;
	int				registrs[REG_NUMBER];
	unsigned 		last_live;
	unsigned		wait;
	struct s_cursor	*prev;
	struct s_cursor	*next;
}					t_cursor;

typedef struct		s_crwr	{
	int				nbr_cycles;
	char			opt;
    t_name          *name;
	t_arena			*arena;
	t_players		*players;
	t_cursor		*cursor;
}					t_crwr;


typedef struct        s_op    {
    char            *name;
    size_t            args;
    unsigned char    mask[3];
    size_t            num;
    size_t            wait;
    char            *desc;
    char            args_exists;
    char            dir_is_four;
	void			(*func)(t_crwr *crwr, t_cursor *temp);
}                    t_op;

extern t_op    g_op_tab[];

int					ft_error(char *msg, int err);

void				valid_command(int ac, char **av, t_crwr **crwr);
void				fix_created_players(int ac, char **av, t_players *players, int i);
int                 ft_is_int(char *str);
unsigned			ft_players_count(t_players *list);

void                valid_files(t_players *players);

t_cursor            *fill_arena(t_crwr *crwr);
t_arena				*init_arena(char alive);

t_cursor			*ft_cursor_new(unsigned id, unsigned count_pl);
t_cursor			*ft_cursor_fork(t_cursor *temp, unsigned pc, unsigned id);
//t_cursor			*ft_cursor_del(t_cursor *cursor, t_cursor *temp);
t_cursor			*ft_cursor_del(t_cursor **cursor, t_cursor **temp);
//t_cursor			*ft_cursor_del(t_cursor **cursor);
void				ft_cursor_add(t_cursor **cursor, t_cursor *new);

unsigned			looped(int num1, int num2);
int					get_direct(void *arena, unsigned pc, char size_four);
int					get_indirect(void *arena, unsigned pc, unsigned cur_pc);

t_name				*free_players(t_crwr **crwr);
void				arena(t_crwr *crwr, t_arena *arena);
void				cycle(t_crwr *crwr);

void				live(t_crwr *crwr, t_cursor *temp);
void				ld(t_crwr *crwr, t_cursor *temp);
void				lld(t_crwr *crwr, t_cursor *temp);
void				st(t_crwr *crwr, t_cursor *temp);
void				sti(t_crwr *crwr, t_cursor *temp);
void				add(t_crwr *crwr, t_cursor *temp);
void				sub(t_crwr *crwr, t_cursor *temp);
void				and(t_crwr *crwr, t_cursor *temp);
void				or(t_crwr *crwr, t_cursor *temp);
void				xor(t_crwr *crwr, t_cursor *temp);
void				zjmp(t_crwr *crwr, t_cursor *temp);
void				aff(t_crwr *crwr, t_cursor *temp);
void				cfork(t_crwr *crwr, t_cursor *temp);
void				lfork(t_crwr *crwr, t_cursor *temp);
void				ldi(t_crwr *crwr, t_cursor *temp);
void				lldi(t_crwr *crwr, t_cursor *temp);


void				pr(t_crwr *crwr);
void				pri(t_cursor *cursor);



void                debug(t_arena *arena, t_cursor *temp, unsigned num);
#define A1 "Cycles:       "
#define A2 "Alive:        "
#define A3 "nbr_live:     "
#define A4 "Cycle_to_die: "
#define A9 "Operation:    "
#define A5 "ID of cursor: "
#define A6 "pc of cursor: "
#define A7 "last_live:    "
#define A8 "Registrs:     "
#define A10 "Arguments:    "
#define A11 "Arg1:         "
#define A12 "Arg2:         "
#define A13 "Arg3:         "
#define A21 "\n"
#define A22 "---"
#define A23 "REG"
#define A24 "DIR"
#define A25 "IND"
#define A26 " | "
#define A27 "Action:       "
