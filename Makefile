NAME			=	pipex
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC_P			=	srcs
SRCS			=	$(wildcard $(SRC_P)/*.c)
OBJ_P			=	objs
OBJS			=	$(patsubst $(SRC_P)/%.c, $(OBJ_P)/%.o, $(SRCS))

RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
NC				=	\033[0m

.DEFAULT_GOAL	=	all
HEADER			=	./incs/pipex.h Makefile

all:				$(NAME)

$(OBJ_P)/%.o:		$(SRC_P)/%.c $(HEADER)
						-@mkdir -p $(OBJ_P)
						-@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS)
						-@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 2>/dev/null && \
						echo "$(GREEN)Build complete!$(NC)" || \
						{ echo "$(RED)Oops! Compilation unsuccessful due to errors.$(NC)"; false; }

clean:
						-@$(RM) $(OBJ_P)
						@echo "$(RED)Object files cleaned!$(NC)"

fclean:				clean
						-@$(RM) $(NAME)
						@echo "$(RED)Project cleaned$(NC)"

re:					fclean all

.PHONY:	all clean fclean re

#
#$(NAME):			$(OBJS)
#						-@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
#						@echo "$(GREEN)Build complete!$(NC)"
#how to make show this message only when compiling done without errors, otherwise show message that Compilation failed due to errors.
#