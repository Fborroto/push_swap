# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 22:02:43 by fborroto          #+#    #+#              #
#    Updated: 2023/09/03 23:36:42 by fborroto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


SRC = $(MAIN_SRC) $(UTILITIES_SRC)

MAIN_SRC = src/*.c

OBJ = *.o

#CFLAGS = -Wall -Wextra -Werror 

RM = rm -rf

STACK = $(shell python3 gen/gen.py 5)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "     - Compiling $(NAME)..."
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(GREEN)"- Compiled -"
	@rm -rf $(OBJ)

$(OBJ): $(SRC)
	@echo "     - Making object files..."
	@gcc -c $(SRC) $(CFLAGS)

gen: all
	@./$(NAME) $(STACK)

test:all
	@./$(NAME) -37 412 -486 -171 202
leak:all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(STACK)

clean: 
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re