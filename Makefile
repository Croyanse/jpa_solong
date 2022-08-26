# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 18:20:36 by jpaterno          #+#    #+#              #
#    Updated: 2022/07/26 18:20:38 by jpaterno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

N_SOLONG = so_long
N_LIBA = libft.a

SRC =	main.c \
		utils.c \
		bloc.c \
		utils2.c \
		canireach.c \
	
OBJLIB = $(LIBFT:.c=.o)
OBJ = $(SRC:*.c=./.o)

all: $(N_SOLONG)

$(N_SOLONG): $(OBJ)
	make -C libft
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -I /usr/local/include -Wall -Wextra -Werror $(OBJ) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(N_SOLONG)

clean:
	rm -f main.o utils.o bloc.o utils2.o canireach.o $(OBJLIB)

fclean: clean
	rm -f ./$(N_SOLONG)
	rm -rf *.dSYM
	make fclean -C libft

save1:
	rm -rf /Users/jpaterno/Documents/SAVE1/*
	cp -rf * /Users/jpaterno/Documents/SAVE1/
save2:
	rm -rf /Users/jpaterno/Documents/SAVE2/*
	cp -rf * /Users/jpaterno/Documents/SAVE2/

fspace:
	rm -rf ~/Library/**.42_cache_bak*; rm -rf ~/**.42_cache_bak; brew cleanup
	wipe


re: fclean all

