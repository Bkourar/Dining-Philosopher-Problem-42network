NAME := philo
CC := gcc
CFLAGS := -Wall -Werror -Wextra
OBJS_DIR := objs/
SRCS := $(wildcard *.c)
HDER := $(wildcard *.h)
OBJ := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all	:	$(OBJS_DIR) $(NAME)

$(OBJS_DIR)	:
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o	:	%.c $(HDER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -pthread

fclean	: clean
	rm -f $(NAME)

clean	:
	rm -r $(OBJS_DIR)

re	:	fclean all

.phone	:	clean