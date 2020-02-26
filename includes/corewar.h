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

#define OPT_DUMP "-dump"
#define OPT_N "-n"
#define OPT_V "-v"

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
	int	    		cycles;
    int             cycles_without_check;
	int		    	cycles_to_die;
	unsigned		nbr_check;
    void            *field;
    void            *par_field;
    t_visu          *visu;
}					t_arena;

typedef struct		s_crwr	{
	int				nbr_cycles;
	char			visu;
    t_name          *name;
	t_arena			*arena;
	t_players		*players;
}					t_crwr;

typedef struct		s_cursor	{
    unsigned          id;
    char            pid;
	char			carry;
	unsigned		num_code;
	unsigned			pc;
	unsigned			step;
	int				*registrs;
	int 			last_live;
	unsigned			wait;
	struct s_cursor	*next;
}					t_cursor;

typedef struct        s_op    {
    char            *name;
    size_t            args;
    unsigned char    mask[3];
    size_t            num;
    size_t            wait;
    char            *desc;
    char            args_exists;
    char            dir_is_four;
}                    t_op;

extern t_op    g_op_tab[];

int					ft_error(char *msg, int err);

void				valid_command(int ac, char **av, t_crwr **crwr);
void				fix_created_players(int ac, char **av, t_players *players, int i);
int                 ft_is_int(char *str);
size_t            ft_players_count(t_players *list);

void                valid_files(t_players *players);

t_cursor            *fill_arena(t_crwr *crwr);
t_arena             *init_arena(char alive);

t_cursor            *ft_cursor_new(size_t id, size_t count_pl);
void                ft_cursor_add(t_cursor **cursor, t_cursor *new);

size_t                looped(int num1, int num2);
int                    get_direct(void *arena, size_t pc, char size_four);
int                    get_indirect(t_cursor *cursor, void *arena, size_t pc);

t_name              *free_players(t_crwr **crwr);
void                arena(t_crwr *crwr, t_cursor *cursor);





int                 get_arena_attr(unsigned char ch);
int                 get_arena_pair(unsigned char ch);

void				live(t_crwr **crwr, t_cursor **cursor, int num);
void				zjmp(t_cursor **cursor, int num);
void				crwr_fork(t_crwr **crwr, t_cursor **cursor, t_cursor *cur_cur, int num);
void				crwr_lfork(t_crwr **crwr, t_cursor **cursor, t_cursor *cur_cur, int num);
void				aff(t_cursor *cursor, unsigned char reg, char visu);
void				add(unsigned char *field, t_cursor **cursor);
void				sub(unsigned char *field, t_cursor **cursor);
void				and(t_cursor **cursor, void *arena, char arg);
void				or(t_cursor **cursor, void *arena, char arg);
void				xor(t_cursor **cursor, void *arena, char arg);
void				ld(t_cursor **cursor, void *arena);
void				lld(t_cursor **cursor, void *arena);
void				st(t_cursor **cursor, t_arena **arena, char arg, t_crwr *crwr);
void				sti(t_cursor *cursor, t_arena **arena, char arg, t_crwr *crwr);
void				ldi(t_cursor **cursor, void *arena, char arg);
void				lldi(t_cursor **cursor, void *arena, char arg);


char				player_exists(t_players *players, int id);
t_cursor            *ft_cursor_del_id(t_cursor **cursor, size_t id, t_crwr **crwr);
t_cursor			*ft_cursor_fork(t_cursor *cursor, size_t pc, size_t new_id, int cycles);
void				ft_cursor_add(t_cursor **cursor, t_cursor *new);
size_t              new_cursor_id(t_cursor **cursor);

//int					check(t_crwr **crwr, t_cursor **cursor);
void				cycle(t_crwr **crwr, t_cursor **cursor);

void				visu(t_crwr **crwr);

void				check_visu(t_arena **arena);
void				add_visu(t_visu **visu, t_visu *new);
void				add_visu_last(t_visu **visu, t_visu *new);
t_visu				*del_visu(t_visu **visu, t_visu *del);
t_visu				*new_visu(size_t pc, char count);
void				need_add_visu(t_arena **arena, size_t pc, char count);

