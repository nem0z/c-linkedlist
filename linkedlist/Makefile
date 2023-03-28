SRC := $(filter-out %.test.c, $(wildcard **/*.c))

TEST_SRC := $(wildcard **/*.test.c)

NAME	=	liblinkedlist.a

TEST_NAME = unit_test.o

OBJ	=	$(SRC:.c=.o)

TEST_OBJ	=	$(SRC:.c=.o) $(TEST_SRC:.c=.o)

DIR_GCOVR	=	gcovr/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)
	rm -f *.gcda
	rm -f *.gcno
	rm -rf $(DIR_GCOVR)

fclean: clean
	rm -rf $(NAME)
	rm -f ${TEST_NAME}

re: fclean all

test: clean $(TEST_OBJ)
	$(CC) -o ${TEST_NAME} ${SRC} $(TEST_SRC) --coverage -lcriterion
	./${TEST_NAME}

gcovr: test
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude='.*test.*' --html --html-details --html-title $(NAME) -o $(NAME).html