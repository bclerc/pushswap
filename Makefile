NAME = pushswap
PROJECT_NAME = pushswap

SOURCES_FOLDER = ./
INCLUDES_FOLDER = includes/libft/

OBJECTS_FOLDER = ./

LIBS = libft

SOURCES = \
		./src/push_swap.c \
		./src/clean.c \
		./src/quicksort.c \
		./src/median.c \
		./src/algo_utils.c \
		./src/small_sort.c \
		./src/big_sort.c \
		./src/three_sort.c \
		./src/utils.c \
		./src/five_sort.c \
		./src/function/function_p.c \
		./src/function/function_r.c \
		./src/function/function_rr.c \
		./src/function/function_s.c

OBJECTS = $(SOURCES:.c=.o)

FSANITIZE = -fsanitize=address
FLAGS =
CC = clang

NO_COLOR =		\033[38;5;15m
OK_COLOR =		\033[38;5;2m
ERROR_COLOR =	\033[38;5;1m
WARN_COLOR =	\033[38;5;3m
SILENT_COLOR =	\033[38;5;245m
INFO_COLOR =	\033[38;5;140m

.PHONY: all re clean fclean libft force doclean

all: $(NAME)

$(LIBS):
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@printf "\n$(NO_COLOR)-------- $(INFO_COLOR)Libft $(NO_COLOR)--------\n"
	@make -C includes/$(@)
	@printf "$(NO_COLOR)-----------------------\n\n"

$(NAME): $(OBJECTS) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L$(INCLUDES_FOLDER) -lft
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

force: $(OBJECTS)
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -g
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

%.o: %.c
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -c $< -o $@
	@printf "$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

clean:
	@make -C includes/$(LIBS) clean
	@rm -f $(OBJECTS)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed all objects$(NO_COLOR).\n"

fclean: clean
	@make -C includes/$(LIBS) fclean
	@rm -f $(NAME)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"

doclean: all clean

re: fclean all
