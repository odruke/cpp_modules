###VARIABLES###

# name of the executable
NAME = megaphone

# compilator and compilation flags
CC = g++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98


# files
SRC = megaphone.cpp
OBJ = $(SRC:.c=.o)


#####RULES####

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

# create .o file
%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@


# delete just file OBJ_DIR and o file inside
clean:
	@rm -rf $(OBJ_DIR)


# executes clean and deletes the executable
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
