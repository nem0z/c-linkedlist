SRC	=	main.c

LDFLAGS	=	-L../linkedlist/ -llinkedlist

CFLAGS	=	-Iinclude -W -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	bin.o

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all