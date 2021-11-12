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
				src/utils.c

SRCS_BONUS	 =	bonus/pipex_bonus.c \
				bonus/free_bonus.c \
				bonus/get_path_bonus.c \
				bonus/utils_bonus.c

OBJS 		= 	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

CC 			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -g -g3
RM			= 	rm -f
LIBPATH		=	libft/
LIB 		=	libft/libft.a
NAME		= 	pipex
NAME_BONUS	=	pipex_bonus

all:			${NAME}

bonus:			${NAME_BONUS}

# .c.o:
# 				${CC} -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
				make -C $(LIBPATH)
				${CC} $(CFLAGS) ${OBJS} ${LIB} -o ${NAME}

$(NAME_BONUS): 	$(OBJS_BONUS)
				make -C $(LIBPATH)
				${CC} $(CFLAGS) ${OBJS_BONUS} ${LIB} -o ${NAME_BONUS}

clean:
				make -C ${LIBPATH} clean
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				make -C ${LIBPATH} fclean
				${RM} ${NAME}  ${NAME_BONUS}

re:				fclean all

.PHONY:			bonus all clean fclean re