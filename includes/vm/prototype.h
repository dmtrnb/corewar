/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:26 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/16 09:51:36 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "struct.h"

int					ft_error(char *msg, int err);
int					ft_usage(void);

void				valid_command(int ac, char **av, t_crwr **crwr);
void				fix_created_players(int ac, char **av, t_players *players, \
																	int count);
int					ft_is_int(char *str);
unsigned			ft_players_count(t_players *list);

void				valid_files(t_players *players);

t_cursor			*fill_arena(t_crwr *crwr, unsigned i);
t_arena				*init_arena(char alive);

t_cursor			*ft_cursor_new(unsigned id, unsigned count_pl);
t_cursor			*ft_cursor_fork(t_cursor *temp, unsigned pc, unsigned id);
t_cursor			*ft_cursor_del(t_cursor **cursor, t_cursor **temp);
void				ft_cursor_add(t_cursor **cursor, t_cursor *new);

unsigned			looped(int num1, int num2);
int					get_direct(void *arena, unsigned pc, char size_four);
int					get_indirect(void *arena, unsigned pc, unsigned cur_pc);

t_name				*free_players(t_crwr **crwr);
void				check(t_arena *arena, t_cursor **cursor);
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

void				free_all(t_crwr *crwr);

t_visu				*get_visu(t_crwr *crwr);
unsigned			get_arena_pair(unsigned char ch);
unsigned			get_arena_attr(unsigned char ch);
unsigned			count_of_cursor(t_cursor *cursor);
void				get_key(t_visu *visu);
void				draw_box(unsigned line, unsigned column, \
													unsigned y, unsigned x);
void				print_visu_buy(char *str, unsigned y, unsigned x, \
																unsigned len);
void				visu_arena(t_crwr *crwr, t_arena *arena, t_visu *visu);
void				visu_update(t_crwr *crwr);
void				get_visu_windows(t_arena *arena, t_cursor *cursor, \
																t_visu *visu);

void				debug(t_crwr *crwr, t_cursor *temp);
int					get_arg(unsigned char *field, t_cursor *temp, \
											unsigned *pc, unsigned char arg);
void				get_mod(int num, char mod);
void				debug_live(unsigned char *field, t_cursor *temp, \
												t_name *name, unsigned pc);
void				debug_ld(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg);
void				debug_st(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg);
void				debug_add_sub(unsigned char *field, t_cursor *temp, \
																unsigned pc);
void				debug_and_or_xor(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg);
void				debug_zjmp(unsigned char *field, t_cursor *temp, \
																unsigned pc);
void				debug_ldi(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg);
void				debug_sti(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg);
void				debug_fork(unsigned char *field, t_cursor *temp, \
																unsigned pc);
void				debug_aff(unsigned char *field, t_cursor *temp, \
																unsigned pc);

#endif
