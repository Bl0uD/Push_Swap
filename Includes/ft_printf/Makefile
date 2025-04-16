NAME = libftprintf.a

SRCS_DIR = Sources/
OBJ_DIR = Objects/

SRC =	ft_print_c.c \
		ft_print_d.c \
		ft_print_p.c \
		ft_print_s.c \
		ft_print_u.c \
		ft_print_xX.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) créée avec succès !"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects supprimés"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) supprimée"

re: fclean all

dev:
	@make fclean
	@git add .
	@git commit -m "auto update"
	@git push