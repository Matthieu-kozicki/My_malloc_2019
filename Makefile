##
## EPITECH PROJECT, 2019
## standard makefile
## File description:
## Makefile
##

SRC	=	malloc.c \
		linked_list.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I include

NAME	=	 libmy_malloc.so

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	##@echo compile $(NAME)
	$(CC) -c -fpic  $(SRC) $(CFLAGS)
	$(CC) $(OBJ) -shared -o $(NAME)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo Clean .o, $(NAME)
	@rm -rf $(OBJ)

fclean: clean
	@echo Clean $(NAME)
	@rm -rf $(NAME)

re: fclean all
