NAME :=  philo
CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -pthread -o $@

%.o	: %.c %.h
	$(CC) $(CFLAGC) -pthread -c $< -o $@

fclean	: clean
	rm -f $(NAME)

clean	:
	rm -f $(OBJ)

re		: fclean all 

.phone : clean
