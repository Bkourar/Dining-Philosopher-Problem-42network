NAME := philo_bonus
CC := gcc
CFLAGS := -Wall -Werror -Wextra
OBJS_DIR := objs_bo/
SRCS := philo_bon.c parse.c utilse_philo.c run_process.c \
		creat_data.c day.c monitor.c
HDER := philo_bonus.h
OBJ := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

RED = \033[0;31m
GREEN = \033[0;32m
CO = \033[0;37m
BLUE = \033[0;36m

all	:	$(NAME)

$(OBJS_DIR)%.o	:	%.c $(HDER)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)building ......$(CO)$@"

$(NAME)	: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -pthread
	@echo "$(BLUE)Loding [............ 100%] is a maked $(GREEN)$@"

fclean	: clean
	@rm -rf $(NAME)

clean	:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)removed philo"
re	:	fclean all

.phone	:	clean