# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 13:05:51 by mivogel           #+#    #+#              #
#    Updated: 2025/07/23 11:54:07 by mivogel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include make/colors.mk

TERM_WIDTH := $(shell tput cols)
SHELL = /bin/bash

SRCS_PATH = ./srcs/
SRCS += ft_atoi.c ft_atol.c ft_atoll.c ft_bzero.c ft_calloc.c ft_free.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isnum.c ft_isprint.c \
	    ft_isspace.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_print_tab.c ft_printf_fun.c ft_printf.c ft_putchar_fd.c \
	    ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	    ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tablen.c ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c\
		ft_tabcpy.c
# SRCS += ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
# 		  ft_free.c get_next_line_bonus.c get_next_line_utils.c

INC = -I includes

OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}
OBJS_PATH = ./objs/

BONUS_OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${BONUS_SRCS}}
BONUS_OBJS_PATH = ./bonus_objs/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

vpath %.c ${SRCS_PATH}

NAME = libft.a
BONUS_NAME = libft_bonus.a

all:	${NAME}

${OBJS}: ${OBJS_PATH}/%.o: %.c Makefile
	@	mkdir -p ${OBJS_PATH}
	@	$(COLORCOMPIL)
	@	${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}:  ${OBJS}
	@	ar -rsc ${NAME} ${OBJS}
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "→ $(NAME) OK!\n"$(NC)

clean:	
	@	rm -rf ${OBJS_PATH}

fclean:	clean
	@	rm -f ${NAME}

re:	fclean all

include make/colorcompil.mk

.PHONY: all clean fclean re
