##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Mon Dec 03 15:08:54 2012 vincent leroy
## Last update Thu Dec 20 10:16:11 2012 maxime ginters
##

SRC	= op.c \
	  main.c \
	  name.c \
	  compile.c \
	  err.c \
	  header.c \
	  add_cmd.c \
	  get_type.c \
	  create_cmd_hex.c \
	  create_label_hex.c \
	  list_to_hexa.c

OBJ	= $(SRC:.c=.o)

NAME	= asm

CC	= gcc

RM	= rm -f

MAKE	= make -C

LIB	= ../lib/

LIST	= ../lib/list/

FLAG	= -Wall -Wextra
FLAG	+= -g

CFLAGS	= $(FLAG)
CFLAGS	+= -I$(LIB)
CFLAGS	+= -I$(LIST)

LDFLAGS	= $(FLAG)
LDFLAGS	+= -L$(LIB) -lmy
LDFLAGS	+= -L$(LIST) -llist

all: my $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

my:
	$(MAKE) $(LIB)

clean:
	$(MAKE) $(LIB) clean
	$(MAKE) $(LIST) clean
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all my clean fclean re
