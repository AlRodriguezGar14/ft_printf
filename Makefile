# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 18:30:09 by alberrod          #+#    #+#              #
#    Updated: 2023/12/18 22:33:05 by alberrod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = cc
HEADERS_DIR = .
CFLAGS   = -Wall -Wextra -Werror -g -I $(HEADERS_DIR)
NAME     = libftprintf.a
RM       = rm -rf

CFILES = ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
	   ft_strjoin.c	ft_strmapi.c ft_strtrim.c ft_isalnum.c	\
	   ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c \
	   ft_strncmp.c	ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c \
	   ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c \
	   ft_tolower.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c \
	   ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c \
	   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c \
	   ft_lstadd_front_bonus.c ft_lstiter_bonus.c ft_lstnew_bonus.c \
	   ft_lstclear_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_putchar.c \
	   ft_uint_putnbr.c ft_printf.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

test: 
	cc tester.c libftprintf.a -g && ./a.out

.PHONY: all clean fclean re
 