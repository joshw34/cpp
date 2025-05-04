NAME = harlFilter

SRC_DIR = ./src
INC_DIR = ./inc

SRC_FILES =	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Harl.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

REMOVE = rm -f
CC = clang++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -I$(INC_DIR)

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
