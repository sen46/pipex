# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 22:34:58 by ssawa             #+#    #+#              #
#    Updated: 2025/08/25 14:00:00 by ssawa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################
#            Library Settings          #
########################################

NAME        = pipex

LIBFT       = ./incs/libft/libft.a
LIBFT_DIR   = ./incs/libft

########################################
#        Compiler Configuration        #
########################################

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I./incs -I$(LIBFT_DIR)

RM          = rm -f
RM_DIR      = rm -rf

MAKEFLAGS  += --no-print-directory

########################################
#       Source & Object Files          #
########################################

SRC = \
	srcs/free.c \
	srcs/find_path_from_envp.c \
	srcs/initialize.c \
	srcs/main.c \
	srcs/validate.c \
	srcs/process.c \
	srcs/get_cmd_path.c \
	srcs/ft_strjoin3.c \

OBJDIR   = objs
OBJ      = $(SRC:%.c=$(OBJDIR)/%.o)

########################################
#               Rules                  #
########################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) -s

$(OBJDIR):
	@mkdir -p $(OBJDIR) $(OBJDIR)/srcs

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean -s
	$(RM_DIR) $(OBJDIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean -s
	$(RM_DIR) $(OBJDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
