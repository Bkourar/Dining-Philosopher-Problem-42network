NAME := philo
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -fsanitize=thread
OBJS_DIR := objs/
SRCS := data.c days.c parse.c philo.c run_threads.c setting.c timeing.c \
		utilse_philo.c
HDER := philo.h
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