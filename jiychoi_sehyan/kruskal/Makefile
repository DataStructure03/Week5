NAME	=	kruskal

CC		=	gcc
# CF		=	-Wall -Wextra -Werror -I ./
CF		=	-g3 -fsanitize=address -I ./
SRC	=	../arraygraph.c kruskal.c union_find.c

SRC_DIR = ./

SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CF) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CF) $(SRCS) -o $(NAME)
	make clean

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)


re		:	fclean	all

.PHONY	:	all clean fclean re