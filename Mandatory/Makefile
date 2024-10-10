NAME := philo
CC := gcc
CFLAGS := -Wall -Werror -Wextra
OBJS_DIR := objs/
SRCS := data.c days.c parse.c philo.c run_threads.c setting.c timeing.c \
		utilse_philo.c
HDER := philo.h
OBJ := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all	:	$(NAME)

$(OBJS_DIR)%.o	:	%.c $(HDER)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -pthread

fclean	: clean
	rm -rf $(NAME)

clean	:
	rm -rf $(OBJS_DIR)

re	:	fclean all

.phone	:	clean