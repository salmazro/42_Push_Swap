# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 12:55:18 by salmazro          #+#    #+#              #
#    Updated: 2022/11/24 18:18:12 by oabushar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g

SRCS        :=      A_operations.c \
                          B_operations.c \
                          linkedList.c \
                          linkedList2.c \
                          main.c \
                          parse.c \
                          parse_big.c \
                          parse_sort.c \
                          rotate.c \
                          sort.c \
						  libft.c \
						  free.c \
						  split.c

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
