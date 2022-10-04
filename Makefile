DEBUG_DELETE_THIS_PLS_FOR_THE_LOVE_OF_GOD = src/debug.c

NAME = push_swap
BONUS_NAME = checker

COMPILER 	= clang
FLAGS		= -Wall -Werror -Wextra
LIBRARY		= -L./libs -lft -lftprintf
SOURCE		= src/main.c \
				src/solver.c
			
COMMON_SRC = src/err_handler.c \
				src/stack_handler.c \
				src/stack_instructions.c \
				$(DEBUG_DELETE_THIS_PLS_FOR_THE_LOVE_OF_GOD)

BONUS_SRC	= src_bonus/checker.c \
				src_bonus/checker_input.c

GNL_SRC		= libs/srclibs/gnl/get_next_line.c \
				libs/srclibs/gnl/get_next_line_utils.c


$(NAME): $(SOURCE)
	$(COMPILER) $(FLAGS) $(SOURCE) $(COMMON_SRC) $(LIBRARY) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)
fclean: clean libftclean printfclean libclean
	$(info ALL CLEAN BABYYY)
re:

libs: libft printf

libft:
	$(MAKE) -C ./libs/srclibs/42_libft 

printf:
	$(MAKE) -C ./libs/srclibs/ft_printf 

libftclean:
	$(MAKE) -C ./libs/srclibs/42_libft clean

printfclean:
	$(MAKE) -C ./libs/srclibs/ft_printf clean

libclean:
	rm -f ./libs/lib*.a

bonus:
	$(COMPILER) $(FLAGS) $(BONUS_SRC) $(COMMON_SRC) $(GNL_SRC) $(LIBRARY) -o $(BONUS_NAME)