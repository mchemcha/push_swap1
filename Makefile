SRCS  =  finel_linked.c libft.c  push_swap.c parsing.c ft_error.c instraction.c print_lst.c index_list.c Longest_algo.c best_move.c sort_3_4_5.c sort_algo.c
NAME = push_swap
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address 
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} $(FLAGS) ${OBJS} -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@	

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean