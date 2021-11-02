SRCS	 	=

SRCS_BONUS	 =

OBJS 		= 	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

CC 			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -g -g3
RM			= 	rm -f
NAME		= 	pipex
NAME_BONUS	=	pipex_bonus

all:			${NAME}

bonus:			${NAME_BONUS}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

$(NAME_BONUS): 	$(OBJS_BONUS)
				${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME_BONUS}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY:			bonus all clean fclean re
