##
## EPITECH PROJECT, 2018
## Evalexpr
## File description:
## Makefile
##

SRC		=	./source/main.c		\
			./source/mpnfload.c

OBJ		=	$(SRC:.c=.o)

NAME	=	101pong

all:	clean fclean $(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		gcc -o $(NAME) $(SRC) -Llib/my/. -lmy -lm

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:
		fclean $(NAME)

auteur:
		echo $(USER) > auteur
