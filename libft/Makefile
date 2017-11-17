# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 15:30:29 by ele-cren          #+#    #+#              #
#    Updated: 2017/05/31 13:23:09 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG1 = -Wall -Wextra -Werror

FLAG2 = -I include

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putnbr.c \
	  ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
	  ft_strequ.c ft_striter.c ft_strlcat.c ft_strlen.c ft_strncat.c \
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c \
	  ft_tolower.c ft_toupper.c ft_memalloc.c ft_memcmp.c ft_strstr.c \
	  ft_memdel.c ft_strdel.c ft_strnstr.c ft_striteri.c ft_strmap.c \
	  ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	  ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_lstiter.c ft_isescape.c ft_nbrlen.c ft_lstmap.c \
	  ft_swap.c ft_strduptoc.c ft_freestrjoin.c get_next_line.c \
	  ft_putlinefeed.c ft_cw.c ft_pow.c ft_hex_to_dec.c \
	  ft_hex_to_rgb.c ft_itoa_base.c ft_rgb_to_hex.c ft_rgb_to_dec.c \
	  ft_tabdel.c ft_inttabdel.c ft_get_digits.c ft_cw_m.c ft_strsplit_m.c \
	  ft_tablen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(FLAG) $(FLAG2)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re: fclean all
