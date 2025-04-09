NAME = libft.a

SRC_DIR = Fonctions
OBJ_DIR = Objects

SRC = $(wildcard $(SRC_DIR)/*.c)
BONUS = $(filter %_bonus.c, $(SRC))

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus dev

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Nettoyage des fichiers objets..."
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🧼 Suppression de la librairie compilée..."
	rm -f $(NAME)

re: fclean all

dev:
	make fclean
	git add .
	git commit -m "auto update"
	git push
