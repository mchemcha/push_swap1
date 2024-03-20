SRCS  =  finel_linked.c libft.c libft_1.c  push_swap.c parsing_1.c parsing_2.c ft_error.c rotate.c  \
		index_list.c Longest_algo.c best_move.c sort_3_4_5.c sort_algo.c utils.c linked_list2.c p_a_p_b.c swap.c rev_rotate.c
SRCSB = get_next_line.c utils.c parsing_1.c parsing_2.c ft_error.c rotate.c libft.c libft_1.c finel_linked.c checker.c  p_a_p_b.c swap.c rev_rotate.c

NAME = push_swap
NAMEBONUS = checker 
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSB:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address 
RM = rm -rf

all: ${NAME}

bonus :${NAMEBONUS}

${NAME}: ${OBJS}
	${CC} $(FLAGS) ${OBJS} -o $(NAME)

${NAMEBONUS}: ${OBJSBONUS}
	${CC} $(FLAGS) ${OBJSBONUS} -o $(NAMEBONUS)

%.o: %.c push_swap.h 
	$(CC) $(FLAGS) -c $< -o $@	

clean:
	$(RM) $(OBJS) $(OBJSBONUS) 

fclean: clean
	$(RM) $(NAME) $(NAMEBONUS)

re: fclean all

.PHONY: clean