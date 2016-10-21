# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/21 12:14:25 by cchameyr          #+#    #+#              #
#    Updated: 2016/10/21 15:09:29 by cchameyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =				main.c \
					get_next_line.c

SRCS =				$(addprefix srcs/, $(FILES))

OBJS =				$(addprefix objs/, $(FILES_SWAP:.c=.o))

CC =				gcc

NAME =				lem-in

LIBFT =				libft/libft.a

DEBUGSEGFAULT =		-fsanitize=address

FLAGS =				-Wall -Wextra -Werror $(DEBUGSEGFAULT)

RM =				rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)
	@make objs_mv

objs_mv:
	@mkdir objs
	@mv $(FILES:.c=.o)

objs_rm:
	@$(RM) objs
	@$(RM) $(FILES:.c=.o)

$(LIBFT):
	make -C ./libft/

clean: objs_rm
	make clean -C ./libft/

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re: fclean all

r: objs_rm
	$(RM) $(NAME)
	@make
