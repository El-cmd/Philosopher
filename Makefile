NAME = philo
CC = gcc
SRCS = philo.c
FLAG = -Wall -Werror -Wextra
RM = rm -rf



all: $(NAME)

clean: $(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all