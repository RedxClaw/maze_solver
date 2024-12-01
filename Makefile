CC = gcc # Le compilateur C
CFLAGS = -Wall -Wextra -Werror -Wunused -Wshadow -I$(INCLUDES) # Les options passees au compilateurws

INCLUDES = includes

MAIN_SRC_DIR = sources
MAIN_SRC = $(shell find $(MAIN_SRC_DIR) -name "*.c")

MAIN_OBJ_DIR = obj
MAIN_OBJ = $(patsubst $(MAIN_SRC_DIR)/%.c, $(MAIN_OBJ_DIR)/%.o, $(MAIN_SRC))

NAME = MazeSolver

all: $(NAME)

$(NAME) : $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(MAIN_OBJ_DIR)/%.o: $(MAIN_SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(MAIN_OBJ_DIR)
	rm -rf output_backtracking.txt
	rm -rf output_branchAndBound.txt

fclean: clean
	rm -f $(NAME)

re: fclean all

# debug: 
# 	$(CFLAGS) += -g3
# debug: re

.PHONY: all clean fclean re