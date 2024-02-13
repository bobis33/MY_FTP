##
## EPITECH PROJECT, 2024
## myftp
## File description:
## Makefile
##


SRC_MAIN 		=	src/main.c

SRC				=   src/core.c 							    \
                    src/parser.c							\
                    src/server/server.c                     \
                    src/client/client.c						\

SRC_TEST		=	units_tests/test.c

OBJ 			=	$(SRC_MAIN:.c=.o)						\
					$(SRC:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)						\
					$(SRC:.c=.o)


CFLAGS			=	-W -Wall -Wextra -I./include

FLAGS_DEBUG 	= 	-g3

FLAGS_TEST 		=	--coverage -lcriterion

NAME			=	myftp

NAME_TEST		= 	unit_tests

$(NAME):			$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:				$(NAME)

debug: 				CFLAGS += $(FLAGS_DEBUG)

debug:				$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
					find . -name "*.o" -delete

clean_test:         clean
					find . -name "*.gcda" -delete -or -name "*.gcno" -delete
					find . -name "*.log" -delete

fclean:				clean clean_test
					rm -rf $(NAME)
					rm -rf $(NAME_TEST)

tests_run:			CFLAGS += --coverage

tests_run: 			$(OBJ_TEST)
					gcc -o $(NAME_TEST) $(OBJ_TEST) $(CFLAGS) $(FLAGS_TEST)
					./unit_tests --verbose

re:					fclean all

.PHONY: 			all debug clean clean_test fclean tests_run re
