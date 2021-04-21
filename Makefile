# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 15:02:44 by nhamill           #+#    #+#              #
#    Updated: 2020/03/16 09:42:44 by nhamill          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM = asm
NAME_VM = corewar
NAME_DIS = dis_asm

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRC_ASM =	main.c init.c metka.c proc.c useful_helpers.c trim_and_comment.c \
			label.c look_at_list.c some_useful_mass.c spl.c tranc.c negative.c \
			codirovka.c write_to_file.c clean.c write_to_file_spec.c \
			process.c check_labels.c labels_only.c search_label.c op/add.c \
			op/and.c op/aff.c op/forki.c op/ld.c op/ldi.c op/lfork.c op/live.c \
			op/lld.c op/lldi.c op/or.c op/st.c op/sti.c op/sub.c op/xor.c op/zjmp.c

SRC_VM = 	main.c valid_cmd.c help_valid_cmd.c valid_files.c init_arena.c op.c \
			struct_cursor.c help_op.c struct_name.c arena.c error.c  cycle.c \
			live.c ld.c st.c add_sub.c and_or_xor.c zjmp_aff.c fork.c ldi.c \
			init_visu.c help_visu.c visu_update.c visu_get_windows.c \
			create_player.c free_all.c visu_arena.c \
			debug.c debug_op1.c debug_op2.c debug_op3.c debug_op4.c debug_help.c

SRC_DIS =	dis_main.c helpers.c write_inc.c magic.c valid.c read_file.c

DIR_SRCS_ASM = ./srcs/asm
DIR_SRCS_VM = ./srcs/vm
DIR_SRCS_DIS = ./srcs/dis

SRCS_ASM = $(addprefix $(DIR_SRCS_ASM)/,$(SRC_ASM))
SRCS_VM = $(addprefix $(DIR_SRCS_VM)/,$(SRC_VM))
SRCS_DIS = $(addprefix $(DIR_SRCS_DIS)/,$(SRC_DIS))

OBJ_ASM = $(patsubst %.c,%.o,$(SRCS_ASM))
OBJ_VM = $(patsubst %.c,%.o,$(SRCS_VM))
OBJ_DIS = $(patsubst %.c,%.o,$(SRCS_DIS))

DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

DIR_INC = includes
INCS_OP = $(addprefix $(DIR_INC)/,op.h)
INCS_ASM = $(addprefix $(DIR_INC)/,asm/header.h)
INCS_VM = $(addprefix $(DIR_INC)/,vm/corewar.h) $(addprefix $(DIR_INC)/,vm/struct.h) \
		$(addprefix $(DIR_INC)/,vm/prototype.h) $(addprefix $(DIR_INC)/,vm/inc_def.h)
INCS_DIS = $(addprefix $(DIR_INC)/,dis/disassembler.h)

INC_ASM = -I $(addprefix $(DIR_INC)/,asm) -I $(DIR_INC) -I $(DIR_LIB)
INC_VM = -I $(addprefix $(DIR_INC)/,vm) -I $(DIR_INC) -I $(DIR_LIB)
INC_DIS = -I $(addprefix $(DIR_INC)/,dis) -I $(DIR_INC) -I $(DIR_LIB)

LIBIN = -L $(DIR_LIB) -lft

LIBIN_NCURSES = -lncurses

all: lib $(NAME_ASM) $(NAME_DIS) $(NAME_VM)

$(NAME_ASM): $(OBJ_ASM) $(LIB)
		$(CC) -o $@ $(OBJ_ASM) $(LIBIN)

$(NAME_VM): $(OBJ_VM) $(LIB)
		$(CC) -o $@ $(OBJ_VM) $(LIBIN) $(LIBIN_NCURSES)

$(NAME_DIS): $(OBJ_DIS) $(LIB)
		$(CC) -o $@ $(OBJ_DIS) $(LIBIN)

$(DIR_SRCS_ASM)/%.o: $(DIR_SRCS_ASM)/%.c $(INCS_ASM) $(INCS_OP)
		$(CC) $(FLAGS) $(INC_ASM) -c $< -o $@

$(DIR_SRCS_VM)/%.o: $(DIR_SRCS_VM)/%.c $(INCS_VM) $(INCS_OP)
		$(CC) $(FLAGS) $(INC_VM) -c $< -o $@

$(DIR_SRCS_DIS)/%.o: $(DIR_SRCS_DIS)/%.c $(INCS_DIS) $(INCS_OP)
		$(CC) $(FLAGS) $(INC_DIS) -c $< -o $@

lib:
		@make -C $(DIR_LIB)

clean:
		@make -C $(DIR_LIB) clean
		@rm -f $(OBJ_ASM) $(OBJ_VM) $(OBJ_DIS)

fclean: clean
		@make -C $(DIR_LIB) fclean
		@rm -f $(NAME_ASM) $(NAME_VM) $(NAME_DIS)

re: fclean all

.PHONY: all clean fclean re lib
