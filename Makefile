SRCS  =  finel_linked.c libft.c libft_1.c  push_swap.c parsing_1.c parsing_2.c ft_error.c instraction.c print_lst.c \
		index_list.c Longest_algo.c best_move.c sort_3_4_5.c sort_algo.c get_next_line.c get_next_line_utils.c
NAME = push_swap
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address 
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} $(FLAGS) ${OBJS} -o $(NAME)

%.o: %.c push_swap.h get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@	

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean