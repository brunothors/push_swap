RED		=	\033[0;31m
GRN		=	\033[0;32m
BLUE 	= \033[1;36m
WHITE	= \033[0;39m
RST		=	\033[0m

NAME	=	push_swap

FILES	=	\
	main.c \
	double_link.c double_utils.c \
	sort_simple.c quick_sort.c quick_utils_a.c quick_utils_b.c \
	swap.c rotate.c push.c \

SRCDIR	=	src
SRC		=	$(FILES:%.c=$(SRCDIR)%.o)

OBJDIR	=	obj
OBJ		=	${FILES:%.c=$(OBJDIR)/%.o}

CC		=	cc
CFLGS	=	-Wextra -Wall -Werror -g3

LIBFT	=	./libft

INCLUDE	=	-I ./include -I ./libft
LIBS	=	./libft/libft.a
T_LIB		= $(shell test -f ./libft/get_next_line_utils.o && echo "yes" 2>&1)

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLGS) $(OBJ) $(LIBS) $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLGS) $(INCLUDE) -c $< -o $@
	@echo "${GRN}Compile $@ DONE${RST}"

$(LIBS):
	@if ! [ $(T_LIB) ]; then echo "$(BLUE)-*- Creating libft library. -*-$(WHITE)";fi
	@make -C ./libft --no-print-directory

clean:
	@rm -rf $(OBJDIR)
	@make clean -C ./libft --no-print-directory
	@echo "${RED}Objects $(OBJ) DELETED${RST}"

fclean: clean
	@make fclean -sC ./libft
	@rm -rf $(NAME)
	@echo "${RED}$(NAME) DELETED${RST}"

re: clean all

.PHONY: all, clean, fclean, re