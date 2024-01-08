# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 18:30:09 by alberrod          #+#    #+#              #
#    Updated: 2023/12/20 16:02:11 by alberrod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = cc
HEADERS_DIR = .
CFLAGS   = -Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME     = libftprintf.a
RM       = rm -rf

CFILES = ft_printf.c printers.c

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
	cc -Wall -Wextra -Werror -fsanitize=address test_ft_printf.c libftprintf.a -g && ./a.out

.PHONY: all clean fclean re
 