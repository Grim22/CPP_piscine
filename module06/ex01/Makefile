SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = serialization
CC = clang++
FLAGS = -Werror -Wall -Wextra --std=c++98

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