# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 21:25:23 by anemesis          #+#    #+#              #
#    Updated: 2022/05/25 17:48:54 by anemesis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

NAME_B		=	minishell_bonus

HEADER		=	shell.h

HEADER_B	=	shell_bonus.h

SRCDIR		=	src

SRCDIR_B	=	src_bonus

OBJDIR		=	obj

OBJDIR_B	=	obj_bonus

SRC			=	$(wildcard $(SRCDIR)/*.c)

SRC_B		=	$(wildcard $(SRCDIR_B)/*.c)

OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

OBJ_B		=	$(SRC_B:$(SRCDIR_B)/%.c=$(OBJDIR_B)/%.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INC			=	-I $(HEADER) -I ./libft

LIB			=	-L ./libft -lft

# **************************************************************************** #

all : lib $(NAME)

lib:
	@make -C ./libft

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus : lib $(NAME_B)

$(NAME_B) : $(OBJ_B) $(HEADER_B)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_B) -o $(NAME_B)

$(OBJDIR_B)/%.o : $(SRCDIR_B)/%.c
	@mkdir -p $(OBJDIR_B)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -rf $(OBJDIR) $(OBJDIR_B)
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME) $(NAME_B)
	@make fclean -C ./libft

re : fclean all bonus

.PHONY : lib all bonus clean fclean re
