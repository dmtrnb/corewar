#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 13:10:09 by nhamill           #+#    #+#              #
#    Updated: 2020/02/27 22:20:19 by nhamill          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

FLGS = -Wall -Wextra -Werror -MMD -MP

CC = gcc

DIR = srcs

SRC = main.c valid_cmd.c help_valid_cmd.c valid_files.c init_arena.c op.c \
		struct_cursor.c help_op.c struct_name.c arena.c error.c  cycle.c \
		live.c ld.c st.c

SRCS = $(addprefix $(DIR)/,$(SRC))

OBJ = $(addprefix $(DIR)/,$(SRC:.c=.o))

DEP = $(addprefix $(DIR)/,$(patsubst %.c,%.d,$(SRC)))

INC = -I includes -I $(LIBFT)

LIB = libft/libft.a

LIBFT = libft

LIB_IN = -L libft -lft -lncurses

all: $(NAME)

$(NAME): $(LIB) $(PRINT) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIB_IN)

LIBA:
	@make -C $(LIBFT)

.PHONY: LIBA

$(LIB): LIBA

$(PRINT): LIBA

%.o: %.c
	$(CC) $(FLGS) -g -c $< -o $@ $(INC)

-include $(DEP)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ) $(DEP)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
