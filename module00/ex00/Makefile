SRC = megaphone.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = megaphone
CC = clang++
FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE)