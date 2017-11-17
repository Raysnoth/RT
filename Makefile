# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 12:54:42 by ele-cren          #+#    #+#              #
#    Updated: 2017/08/23 13:47:21 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = rt

SRC = src/check_types.c src/init.c src/main.c src/parse_lights.c \
	  src/parsing.c src/parse_objects.c src/parse_cam.c src/sdl.c \
	  src/list.c src/error.c src/browse.c src/calc_obj.c src/init2.c \
	  src/draw.c src/thread.c src/light.c src/calc.c src/shadow.c src/end.c \
	  src/tool_calc.c src/settings.c src/set_i.c src/events.c src/set_o.c \
	  src/set_a.c src/set_p.c src/set_d.c src/set_c.c src/c_list.c \
	  src/ev_col.c src/ev_pos.c src/ev_dir.c src/ev_obj.c src/ev_at.c \
	  src/event_obj.c src/set_b.c src/ev_base.c src/set_eff.c src/ev_eff.c \
	  src/event_obj2.c  src/thread_dup.c src/thread_dup2.c \
	  src/thread_suppr_dup.c src/event_cam.c src/free.c src/c_list2.c \
	  src/event_mouse.c src/date.c src/calc_again.c src/normal.c src/filters.c \
	  src/texture.c src/reflexion.c src/refraction.c src/color.c \
	  src/save_scene.c src/thread_dup3.c src/save_scene2.c src/save_scene3.c \
	  src/parsing2.c src/parsing3.c src/parsing4.c

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

FLAGS = -Wall -Wextra -Werror -I ./SDL2/SDL2/include  \
		-I $(HOME)/SDL2/TTF/include/SDL2 -Ofast -I ./libft/include -I \
		./include -g

LIBS = -L./libft -lft -L $(HOME)/SDL2/TTF/lib -lSDL2_ttf -L \
	   $(HOME)/SDL2/SDL2/lib -lSDL2 -lSDL2main

HEADER = include/rt.h libft/include/libft.h

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -o $(NAME) $(LIBS) $(SDLLIBS)
	echo "\033[32m[✔] \033[0m$(NAME)"

obj/%.o : src/%.c $(HEADER)
	test -e $(HOME)/SDL2/SDL2 || (cd SDL2/SDL2 ; \
		./configure --prefix=$(HOME)/SDL2/SDL2 ; make install ; cd -)
	test -e $(HOME)/SDL2/FT || (cd SDL2/FT ; \
		./configure --prefix=$(HOME)/SDL2/FT ; make install ; cd -)
	test -e $(HOME)/SDL2/TTF || (cd SDL2/TTF ; \
		./configure --with-sdl-prefix=$(HOME)/SDL2/SDL2 \
		--with-freetype-prefix=$(HOME)/SDL2/FT --prefix=$(HOME)/SDL2/TTF ; \
		make install ; cd -)
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@
	echo "\033[32m[✔] \033[0m$@"

.PHONY : clean fclean

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31m[✗] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31m[✗] \033[0m$(NAME)"

re : fclean all
