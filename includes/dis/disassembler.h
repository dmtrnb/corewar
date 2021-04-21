/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/16 09:50:41 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASSEMBLER_H
# define DISASSEMBLER_H

# include "op.h"

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define ERR_NBR_NLL "Invaid number of nulls after name"
# define ERR_NBR_CMT "Invaid number of nulls after comment"
# define ERR_MGC_NBR "Invalid magic number"
# define ERR_CRT_S "Couldn't create .s file"
# define ERR_NBR_AGRS "Invalid number of args"
# define ERR_FILE_EXIST "File doesn't exist"
# define ERR_RD_FILE "Error while reading a file"
# define ERR_SIZE "Invalid size of program"
# define ERR_PROG_SIZE "File length doesn't match to program size"
# define ERR_CMT_SIZE "Invalid lenth of comment"
# define ERR_INC "Invalid instruction"
# define ERR_FILE_NAME "Invalid file name"
# define ERR_FILE_FORMAT "Invalid file format"
# define ERR_REG_NUM "invalid register number"

typedef struct				s_dis
{
	int				fd;
	int				op;
	int				cod;
	char			*line;
	char			*ans;
	char			**metka;
	char			**arg;
	int				flag;
	int				dir;
	struct s_line	*next;
	struct s_line	*prev;
}							t_dis;

typedef struct				s_magic
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}							t_magic;

typedef struct				s_flag
{
	int				f;
	int				p;
}							t_flag;

typedef struct				s_all
{
	int				fd;

	char			*name;
	char			*comment;
	char			*instructions;
	char			*file_s;
	char			*file_cor;
	int				file_len;
	t_flag			flag;
	t_magic			*magic;
}							t_all;

typedef struct				s_instruction
{
	int						op;
	int						acb;
	char					**params;
}							t_instruction;

typedef struct				s_op
{
	char					*opstr;
	int						params;
	int						ptype[MAX_ARGS_NUMBER];
	int						num;
	int						cycles;
	char					*description;
	int						acb;
	int						index;
}							t_op;

extern t_op					g_optab[17];

void						ft_exit(char *line);
void						ft_putstr_fd_wide(char c, char *str, int fd);
int							ft_write_inc(char *data, t_op op, t_all *all);
int							ft_short(char *array);
int							ft_int(char *array);
void						ft_print_s(t_all *all);
void						ft_init(t_all *all, int ac, char **av);
char						*ft_s(t_all *all);
void						ft_usage(void);
void						ft_read_name_comment(t_all *all);
int							i_have_no_idea_how_it_works(int x);
void						*read_file(char *filename, int *size);
int							file_len(char *filename);
void						ft_free_all(t_all *all);
void						ft_write_name_comment(t_all *all);
void						ft_cmp_inc(t_all *all, char *str, int size);
void						ft_putstr_to_fd(t_all *all, char *temp);

#endif
