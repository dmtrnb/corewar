/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/16 09:48:58 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "op.h"
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define ANSI_COLOR_RED	 "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define ERR_ARG "error with number of arg : "
# define ERR "error with "

# define ERR_ADD "ADD command"
# define ERR_AFF "AFF command"
# define ERR_AND "AND command"
# define ERR_FORK "FORk command"
# define ERR_FORK_ "lFORk command"
# define ERR_LD "ld command"
# define ERR_LDI "ldi command"
# define ERR_LV "LIVE command"
# define ERR_LLD "lld command"
# define ERR_LLDI "lldi command"
# define ERR_OR "OR command"
# define ERR_ST "st command"
# define ERR_ST_ "sti command"
# define ERR_SUB "sub command"
# define ERR_XOR "xOR command"
# define ERR_JMP "ZJMP command"

# define ERR_LBL_CHAR "Invalid label char"

# define ERR_LD_DIG "sould be a digit in arg"
# define ERR_LD_LBL "invalid label name in arg"
# define ERR_LD_NO_REG "sould be a register in arg"
# define ERR_LD_REG "sould be a digit after 'r' for register in arg"
# define ERR_LD_BAD_REG "Bad register number in arg"

# define ERR_INC "no instruction"
# define ERR_NAME "no name"
# define ERR_COMMENT "no comment"
# define ERR_INC_EXIST "operation doesn't exist, like your girlfriend hahaha "
# define ERR_INC_EXIST_ ":)\ndon't be offended, it's a joke. honestly!"
# define ERR_FILE "no file"

# define ERR_FD "Can't read file"
# define ERR_BAD_NAME "Bad name"
# define ERR_BIG_NAME "Too big name"
# define ERR_LENGHT "Invalid lenght of name or comment"
# define ERR_DBL_NAME "double name"
# define ERR_DBL_CMT "double comment"
# define ERR_NO_NAME_CMT "no name or comment"
# define ERR_CMT "wrong name Or comment"
# define ERR_LBL_EXI "label doesn't exist"

typedef struct		s_line
{
	int				size;
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
}					t_line;

typedef struct		s_all
{
	t_line			*inc_list;
	t_line			*name;
	t_line			*comment;
	char			*file;
	char			*champ;
	int				size;
	int				fd;
	char			*inc[17];
	void			(*op[16])(t_line*);
}					t_all;

void				ft_init(t_all *all);
void				ft_record_inc(t_all *all);
void				ft_record_func(t_all *all);

void				ft_read_file(char *file, t_all *all);
void				ft_process(char *line, t_all *all);
t_line				*ft_create(char *line);
void				ft_error(char *line, char *add);
void				ft_proc_name_com(t_all *all, char *line, int flag, int i);
void				ft_proc_name_com2(t_all *all, int flag, char *new, int s);
void				ft_keep_read(t_all *all, char *temp, int flag, int s);
void				ft_keep_read2(t_all *all, char *new, int flag);

char				*ft_copy_name_com(char *f, char *s);
void				ft_check_len(t_line *new, int flag);

void				ft_add_inc(t_all *all, char *line);
void				ft_proc_metka(t_all *all, char *line);
void				ft_proc_metka2(t_all *all, char *big, char *temp);
char				*ft_stepler(char *what, char *who);
char				*ft_strjoin3(char const *s1, char const *s2,
							char const *s3);
char				*ft_trim(char *line, char *f_qoute);
char				*ft_proc_comment(char *line, char *f_qoute);

char				*ft_afterspace(char *line);
void				ft_clean_all(t_all *all);
void				ft_clean_name_com(t_line *temp);
void				ft_clean_elem(t_line *temp);

void				ft_dis(t_all *all);
void				ft_labels(t_all *all);
char				**ft_strsplit_wide(char const *str, char c);

void				ft_look_at_list(t_all *all);
void				ft_check_inc(t_all *all, t_line *temp);

int					ft_size_mass(char **mass);
void				ft_trim_mass_arg(char **mass);
void				ft_print_mass(char **mass);
void				ft_free_mas(char **arr);

int					ft_h_m(char *str, int c);

void				ld(t_line *oper);
void				ft_ld_arg1(t_line *temp, char *arg);
void				ft_check_ld_number(char *arg);
void				ft_check_ls_label(char *arg);
void				ft_check_reg(char *arg);

void				st(t_line *temp);
void				ft_st_arg2(t_line *temp, char *arg);

void				add(t_line *temp);

void				live(t_line *temp);

void				sub(t_line *temp);

void				zjmp(t_line *temp);

void				forki(t_line *temp);

void				lfork(t_line *temp);

void				aff(t_line *temp);

void				and(t_line *temp);
int					ft_check_trio(char *arg, int i, t_line *temp, int size);

void				or(t_line *temp);

void				xor(t_line *temp);

void				lld(t_line *temp);

void				sti(t_line *temp);
void				ft_check_double(char *arg, int i, t_line *temp);

void				ldi(t_line *temp);

void				lldi(t_line *temp);

char				ft_digit(int num);
int					ft_size_of_str(long long int num, int k);
int					ft_str_int(long long int num, long long int p, char *s);
char				*ft_convert(long long int i, int p, int size);

char				*ft_negative(long long int i, int size);
char				*ft_add_null(char *str, int i);
void				ft_invers(char *str);
void				ft_plus_one(char *str);
long long int		ft_str_binar_int(char *str);

int					ft_check_label_for_command(char *str, t_all *all);
char				*ft_labels_only(char *str);
char				*ft_labels_only2(char *str, int i, int index);
void				ft_trim_label(char *str, t_line *temp);
void				ft_valid_label_chars(char *str);
void				ft_check_space_btwn_labels(char **mass,
							t_all *all, int i, char *line);
int					ft_len(char *str);
char				*ft_check_for_tabs_and_trim(char *str);
void				ft_labels(t_all *all);
void				ft_labels2(t_line *temp, t_all *all,
						char **str, char **old);
int					ft_labels3(t_line *temp,
						char **str, char **old);

void				ft_codirovka(t_all *all);
void				ft_some(t_line *temp);
void				ft_arg(t_line *temp, char *arg);
void				ft_arg2(t_line *temp, char *arg, int size);
void				ft_search_label(t_line *temp, char *arg, int size);
int					ft_search_label2(t_line *temp, char *arg);
int					ft_search_label_forward(t_line *temp, char *arg);
int					ft_search_label_back(t_line *temp, char *arg);

void				ft_general_write(t_all *all);
void				ft_write_magic(int fd);
void				ft_write_name(int fd, char *str, int big_len);
void				ft_write_size(int fd, int size);
void				ft_write_code(t_all *all, int fd);
void				ft_write_null(int fd);
void				ft_str_to_byte(char *str, int fd);

#endif
