/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:10:58 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/15 12:38:57 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_visu	{
	unsigned char	cond;
	WINDOW			*arena;
	WINDOW			*cycles;
	WINDOW			*lives;
	WINDOW			*procces;
	unsigned char	size;
	unsigned		cursor;
	unsigned		count;
	unsigned char	mem_part;
	unsigned char	mem_parts;
}					t_visu;

typedef struct		s_name	{
	char			*name;
	char			*comment;
	unsigned		code_size;
	struct s_name	*next;
}					t_name;

typedef struct		s_player	{
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
	unsigned		nbr_live;
	unsigned		cycles;
	unsigned		cycles_without_check;
	int				cycles_to_die;
	unsigned		nbr_check;
	void			*field;
	void			*par_field;
	t_visu			*visu;
}					t_arena;

typedef struct		s_cursor	{
	unsigned		id;
	unsigned		pc;
	unsigned char	step;
	int				registrs[REG_NUMBER];
	unsigned		last_live;
	unsigned		nc;
	int				wait;
	struct s_cursor	*prev;
	struct s_cursor	*next;
}					t_cursor;

typedef struct		s_crwr	{
	int				nbr_cycles;
	char			opt;
	t_name			*name;
	t_arena			*arena;
	t_players		*players;
	t_cursor		*cursor;
}					t_crwr;

typedef struct		s_op	{
	char			*name;
	size_t			args;
	unsigned char	mask[3];
	size_t			num;
	size_t			wait;
	char			*desc;
	char			args_exists;
	char			dir_is_four;
	void			(*func)(t_crwr *crwr, t_cursor *temp);
}					t_op;

#endif
