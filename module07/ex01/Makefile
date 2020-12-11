SRC = main.cpp Fixed.cpp
OBJ = $(SRC:%.cpp=%.o)
NAME = iter
CC = clang++
FLAGS = -Werror -Wall -Wextra --std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) -c $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE)