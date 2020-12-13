# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 22:15:25 by molivier          #+#    #+#              #
#    Updated: 2020/12/13 21:41:16 by molivier         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= -rcs
RM		= rm -f
RMDIR	= rm -rf

OBJDIR	= obj
HEAD	= libft.h

SRC		= ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_memset.c \
		  ft_memchr.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strdup.c \
		  ft_strmapi.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_atoi.c \
		  ft_itoa.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c

LST		= ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
BONUS	= $(addprefix $(OBJDIR)/,$(LST:.c=.o))

GREEN	= \033[1;32m
PURPLE	= \033[1;35m
RED		= \033[1;31m
YELLOW	= \033[1;33m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(YELLOW)$@ \t$(PURPLE)must be updated with $(WHITE)$(notdir $?)"
	@echo "$(PURPLE)Updating\t$(YELLOW)$@"
	@$(AR) $(ARFLAGS) $@ $?
	@echo "$@ :\t$(GREEN)Indexed / Up to date"

bonus: $(BONUS) | $(NAME)
	@echo "\n$(YELLOW)$| \t$(PURPLE)must be updated with $(WHITE)$(notdir $?)"
	@echo "$(PURPLE)Updating\t$(YELLOW)$|"
	@$(AR) $(ARFLAGS) $| $?
	@echo "$| :\t$(GREEN)Indexed / Up to date"

$(OBJDIR)/%.o: %.c $(HEAD) | $(OBJDIR)
	@echo "$(PURPLE)Compiling\t$(WHITE)$<"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

clean:
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR)'"
	@$(RMDIR) $(OBJDIR)

fclean: clean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME)\n"
	@$(RM) $(NAME)

re: fclean all

norme:
	@norminette $(SRC) $(LST) $(HEAD)

norme3:
	@norminette3 $(SRC) $(LST) $(HEAD)

.PHONY: all bonus clean fclean re norme norme3
