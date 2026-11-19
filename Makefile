# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/03 17:24:02 by julbarri          #+#    #+#              #
#    Updated: 2026/11/14 17:37:01 by julbarri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester
CC = cc
HEADER = ../libft.h
LIBFT = ../libft.a
FLAGS = -Werror -Wall -Wextra -g
SRCS =	main.c				\
	./tests/ft_isalpha_test.c	\
	./tests/ft_isdigit_test.c	\
	./tests/ft_isalnum_test.c	\
	./tests/ft_isascii_test.c	\
	./tests/ft_isprint_test.c	\
	./tests/ft_strlen_test.c	\
	./tests/ft_memset_test.c	\
	./tests/ft_bzero_test.c		\
	./tests/ft_memcpy_test.c	\
	./tests/ft_memmove_test.c	\
	./tests/ft_strlcpy_test.c	\
	./tests/ft_strlcat_test.c	\
	./tests/ft_toupper_test.c	\
	./tests/ft_tolower_test.c	\
	./tests/ft_strchr_test.c	\
	./tests/ft_strrchr_test.c	\
	./tests/ft_strncmp_test.c	\
	./tests/ft_memchr_test.c	\
	./tests/ft_memcmp_test.c	\
	./tests/ft_strnstr_test.c	\
	./tests/ft_atoi_test.c		\
	./tests/ft_calloc_test.c	\
	./tests/ft_strdup_test.c	\
	./tests/ft_substr_test.c	\
	./tests/ft_strjoin_test.c	\
	./tests/ft_strtrim_test.c	\
	./tests/ft_split_test.c		\
	./tests/ft_itoa_test.c		\
	./tests/ft_strmapi_test.c	\
	./tests/ft_striteri_test.c	\
	./tests/ft_putchar_fd_test.c	\
	./tests/ft_putstr_fd_test.c	\
	./tests/ft_putendl_fd_test.c	\
	./tests/ft_putnbr_fd_test.c	\
	./tests/ft_lstnew_test.c	\
	./tests/ft_lstadd_front_test.c	\
	./tests/ft_lstsize_test.c	\
	./tests/ft_lstlast_test.c	\
	./tests/ft_lstadd_back_test.c	\
	./tests/ft_lstdelone_test.c	\
	./tests/ft_lstclear_test.c	\
	./tests/ft_lstiter_test.c	\
	./tests/ft_lstmap_test.c	\
	./tests/ft_lst_utils.c

all : $(NAME)
	valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

$(NAME) : $(HEADER) $(SRCS) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

fast : $(NAME)
	./$(NAME)

$(LIBFT) :
	make -C ..

clean :
	rm -f $(NAME)

re : clean all

.PHONY : all fast clean re
