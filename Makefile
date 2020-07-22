# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trkapous <trkapous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 16:17:17 by trkapous          #+#    #+#              #
#    Updated: 2020/07/20 23:57:34 by tris             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


LIB = libft.a

NAME = sudoku

SRC = parse.c \
	  sudoku.c \
	  solve.c

SRCF = src/
SRCCF = $(addprefix $(SRCF), $(SRC))

HDRF = inc/
HDRRF = $(HDRF)$(NAME).h

CC = clang
FLAG = -Wall -Wextra -g
DEL = rm -f
FDEL = rm -rf

OBJ = $(SRC:.c=.o)
OBJF = obj/
OBJOF = $(addprefix $(OBJF), $(OBJ))
OBJX = mkdir -p $(OBJF) ; mv $(OBJ) $(OBJF) 2> /dev/null

TEST = test
TESTF = test/
# TESTFF = $(addprefix $(TESTF), $(TEST))
TESTFF = test/test3

all: $(NAME)

$(NAME):
	@$(DEL)
	@$(CC) -c $(FLAG) $(SRCCF) -I $(HDRF)
	@$(OBJX)
	@$(CC) $(FLAG) $(OBJOF) -o $(NAME) -L. -lft
	@echo
	@echo "make -> $(NAME) created"
	@echo

clean: start
	@$(FDEL) $(OBJF) $(OBJ)
	@$(DEL)
	@echo
	@echo "clean -> *.o deleted"
	@echo

fclean: clean exclean
	@$(DEL) $(NAME) test.out
	@$(DEL)
	@echo
	@echo "fclean -> $(NAME) deleted"
	@echo

re: fclean all
	@echo
	@echo "re -> $(NAME) reloaded"
	@echo

ex: re $(NAME)
	@echo "\n----------------"
	@echo "--- Bin exec ---"
	@echo "----------------\n"
	@chmod u+x $(NAME)
	@time ./$(NAME) $(TESTFF)

edit:
	@vi -O $(SRCCF) $(HDRRF)

start:
	@echo "################"
	@echo "### MAKEFILE ###"
	@echo "################"

.PHONY: all clean fclean exclean re
