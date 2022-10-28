# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 20:46:58 by user42            #+#    #+#              #
#    Updated: 2022/10/28 18:21:26 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

SRCS			=	srcs/main.c	\
					srcs/clean.c	\
					srcs/message.c	\
					srcs/philo_utils.c	\
					srcs/init.c	\
					srcs/routine.c	\
					srcs/philosophers.c	\
					srcs/cstates.c	\
					../utils/error.c	\
					../utils/ft_atol.c	\
					../utils/ft_lltoa.c	\
					../utils/ft_putnbr.c	\
					../utils/string.c	\
					../utils/time.c	\
					../utils/args.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -g3 -I./include/ -I../utils/ -Wall -Wextra -Werror
LIBS			= -lpthread

NAME			= philo_three

all:
				@make -s $(NAME)


$(NAME):		$(OBJS)
				@printf "$(YELLOW)\t- Compiling [$(NAME)]$(NOC)\n"
				@gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}
				@printf "$(GREEN)\t- Done...$(NOC)\n"

clean:
				@printf "$(YELLOW)\t- Cleaning .o$(NOC)\n"
				@$(RM) $(OBJS)

fclean:			clean
				@printf "$(YELLOW)\t- Deleting $(RED)[$(NAME)] $(NOC)\n"
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
