NAME      = fixed02

CC        = g++ 

FLAGS     = -Wextra -Werror -Wall -std=c++98

SRC_FILES = $(wildcard *.cpp)

OBJ_FILES = $(SRC_FILES:.cpp=.o)

%o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
		$(CC) $(FLAGS) -o $(NAME) $^

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re