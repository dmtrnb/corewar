#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 01:56:27 by nhamill           #+#    #+#              #
#    Updated: 2020/01/18 13:47:16 by nhamill          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_atoi_base.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_itoa.c \
	ft_isascii.c ft_isdigit.c ft_isdigit_base.c ft_isprint.c ft_isspace.c \
	ft_itoa_base.c ft_lstadd.c ft_lstaddlast.c ft_lstaddnum.c ft_lstdel.c \
	ft_lstdelnum.c ft_lstdelone.c ft_lstfold.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
	ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_strcasechr.c ft_strcasecmp.c ft_strcasestr.c ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strcspn.c ft_strdel.c \
	ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strlwr.c ft_strlen.c \
	ft_strjoin.c ft_strlcat.c ft_strmap.c ft_strmapi.c ft_strncasecmp.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c \
	ft_strnew.c ft_strnlen.c ft_strnstr.c ft_strpbrk.c ft_strsep.c ft_strrev.c \
	ft_strrchr.c ft_strsplit.c ft_strspn.c ft_strstr.c ft_strsub.c ft_strtok.c \
	ft_strtrim.c ft_strupr.c ft_swab.c ft_tolower.c ft_toupper.c ft_lstsplit.c \
	ft_list_count.c

OBJ = $(SRCS:.c=.o)

SR~ = $(SRCS:.c=.c~)

all: $(NAME)

$(NAME):
	@gcc $(FLGS) -c $(SRCS) -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(SR~)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
