NAME = philo
CC = gcc
FLAGS = -Wall -Werror -Wextra -pthread
RM = rm -rf

SRC = philo.c dinner.c utils.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
	
clean: 
		$(RM) $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all