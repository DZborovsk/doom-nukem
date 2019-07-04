# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolinko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 15:30:37 by akolinko          #+#    #+#              #
#    Updated: 2019/02/14 23:54:25 by ylisyak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RESET		= \033[m
GREEN       = \033[32m

CC = gcc
FLAG = -Wall -Wextra -Werror
SRS =  ft_putchar.c ft_atoi_base.c ft_putstr.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_atoi.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strrchr.c ft_strstr.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_bzero.c ft_strnstr.c ft_strlcat.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_strclr.c ft_strequ.c ft_strnequ.c ft_striter.c ft_striteri.c ft_strnew.c ft_strdel.c ft_memdel.c ft_memalloc.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_strjoin.c ft_isspace.c ft_wd_count.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_numlen.c ft_count.c ft_max.c ft_abs.c
OBJ = $(SRS:.c=.o)
HEADER =./libft.h 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@rm -rf $(OBJ)
.c.o:
	@$(CC) $(FLAG) -c $< -o $@
	@echo "$(GREEN)█$(RESET)\c)"

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: clean fclean re all
