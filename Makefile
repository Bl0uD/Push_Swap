NAME = push_swap

SRC = ./main.c \
		./Utils/utils.c \
		./Utils/utils2.c \
		./Algorithms/ps_sort.c \
		./Algorithms/ps_sort_big.c \
		./Parsing/ps_check_parsing.c \
		./Instructions/ps_rotate.c \
		./Instructions/ps_reverse_rotate.c \
		./Instructions/ps_push.c \
		./Instructions/ps_swap.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make libft
	$(CC) $(CFLAGS) $(SRC) ./Includes/LibFT/libft.a -o $(NAME)

clean:
	make -C ./Includes/LibFT clean
	@true

fclean: clean
	make -C ./Includes/LibFT fclean
	rm -f $(NAME)

re: fclean all

libft:
	make -C ./Includes/LibFT

dev :
	make fclean
	git add .; git commit -m "auto/dev"; git push
	make all

.PHONY: all clean fclean re libft