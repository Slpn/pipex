# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snarain <snarain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 15:39:52 by snarain           #+#    #+#              #
#    Updated: 2021/11/04 15:39:54 by snarain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	 	=	src/pipex.c \
				src/free.c \
				src/get_path.c \
				src/parse_arg.c \
				src/child_proc.c \
				src/parent_proc.c \
				src/utils.c

# SRCS_BONUS	 =

OBJS 		= 	${SRCS:.c=.o}
# OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

CC 			= 	gcc
# CFLAGS		= 	-Wall -Wextra -Werror -g -g3
RM			= 	rm -f
LIBPATH		=	libft/
LIB 		=	libft/libft.a
NAME		= 	pipex
NAME_BONUS	=	pipex_bonus

all:			${NAME}

bonus:			${NAME_BONUS}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
				make -C $(LIBPATH)
				${CC} ${OBJS} ${LIB} -o ${NAME}

$(NAME_BONUS): 	$(OBJS_BONUS)
				${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME_BONUS}

clean:
				make -C ${LIBPATH} clean
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				make -C ${LIBPATH} fclean
				${RM} ${NAME}  ${NAME_BONUS}

re:				fclean all

.PHONY:			bonus all clean fclean re
