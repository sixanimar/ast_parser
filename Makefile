
NAME := pars

INCLUDES := src/parser.h

SRC :=		src/parser.c \
			src/strjoin.c \
			src/strlen.c

CC = gcc

CFLAGS = -Wall -Wextra

all: clean $(SRC) $(INCLUDES)
	@echo "Compiling"
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compilation done"

clean:
	@rm -f $(NAME)
	@rm -f combined.ast

re: clean all

.PHONY: all clean fclean re
