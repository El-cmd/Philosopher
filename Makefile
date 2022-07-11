NAME = philo
FLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

SRCS = philo.c\
       srcs/mutex.c\
	   srcs/philo_data.c\
	   srcs/time.c\
	   srcs/utils.c

OBJS := $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -pthread -g

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all