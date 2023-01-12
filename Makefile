# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 14:29:15 by mabdelba          #+#    #+#              #
#    Updated: 2023/01/07 23:24:39 by mabdelba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_spl.c \
			 ft_strcpy.c ft_strcat.c
OBJS = $(SRCS:.c=.o)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $<

$(NAME):$(OBJS) 
	ar cr $(NAME) $(OBJS)

all: $(NAME)

bonus: $(BONUS_OBJ) $(OBJS)
	ar cr $(NAME) $(BONUS_OBJ) $(OBJS)

clean: 
	rm -f $(OBJS) $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
