# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 15:31:20 by obouadel          #+#    #+#              #
#    Updated: 2022/01/05 20:39:35 by obouadel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ./philo/philo
NAME_BONUS= ./philo_bonus/philo_bonus

HEADER= ./philo/philo.h

HEADER_BONUS= ./philo_bonus/philo_bonus.h

CC= gcc
CFLAGS = -Wall -Werror -Wextra
THREAD = -pthread

SRCS = 	./philo/philo.c \
		./philo/check_args.c \
		./philo/check_death.c \
		./philo/utils.c \
		./philo/print.c \
		./philo/end_program.c \
		./philo/monitor.c \
		./philo/data_fill.c \

OBJS = $(SRCS:.c=.o)

SRCS_BONUS =	./philo_bonus/philo_bonus.c \
				./philo_bonus/check_args_bonus.c \
				./philo_bonus/utils_bonus.c \
				./philo_bonus/end_program_bonus.c \
				./philo_bonus/data_fill_bonus.c \
				./philo_bonus/monitor_bonus.c \
				./philo_bonus/print_bonus.c \

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
	@echo "\033[30;1m---> \033[0m PHILO      \033[32;1m [OK] \033[0m"
	
%.o: %.c $(HEADER) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER) 
	@$(CC) $(CFLAGS) $(THREAD) $(OBJS) -o $(NAME)

bonus: $(OBJS_BONUS) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) $(THREAD) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "\033[30;1m---> \033[0m PHILO BONUS\033[32;1m [OK] \033[0m"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@echo "\033[30;1m---> \033[0m CLEAN      \033[32;1m [OK] \033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re