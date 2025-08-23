# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 22:34:58 by ssawa             #+#    #+#              #
#    Updated: 2025/08/01 14:33:26 by ssawa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################
#            Library Settings          #
########################################

NAME = pipex

LIBFT       = ./incs/libft/libft.a
LIBFT_DIR   = ./incs/libft

########################################
#        Compiler Configuration        #
########################################

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I./incs -I$(LIBFT_DIR)

########################################
#       Source & Object Files          #
########################################

OBJDIR = objs

SRC = \
	srcs/free.c \
	srcs/find_path_from_envp.c \
	srcs/initialize.c \
	srcs/main.c \
	srcs/validate.c \
	srcs/process.c \
	srcs/get_cmd_path.c \
	srcs/ft_strjoin3.c \

BONUS_SRC = \

OBJ   = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
B_OBJ = $(addprefix $(OBJDIR)/, $(BONUS_SRC:.c=.o))

########################################
#               Rules                  #
########################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(B_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

bonus: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJDIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
