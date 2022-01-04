# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 15:31:20 by obouadel          #+#    #+#              #
#    Updated: 2022/01/03 15:17:40 by obouadel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

HEADER= philo.h \

CC= gcc
CFLAGS = -Wall -Werror -Wextra
THREAD = -pthread

SRCS = 	philo.c \
		check_args.c \
		check_death.c \
		ft_calloc.c \
		print.c \
		ft_atoi.c \
		end_program.c \
		monitor.c \
		data_fill.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "\033[30;1m---> \033[0m PHILO      \033[32;1m [OK] \033[0m"
	
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER) 
	@$(CC) $(CFLAGS) $(THREAD) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "\033[30;1m---> \033[0m CLEAN      \033[32;1m [OK] \033[0m"


fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re