NAME = zombie

SRC_DIR = ./src

SRC_FILES =	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Zombie.cpp \
			$(SRC_DIR)/randomChump.cpp \
			$(SRC_DIR)/newZombie.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

REMOVE = rm -f
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Compiling/Linking"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Ready"

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing .o files"
	@$(REMOVE) $(OBJ_FILES)

fclean:	clean
	@echo "Removing executable"
	@$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
