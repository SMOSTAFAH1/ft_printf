# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2024-09-25 06:19:00 by shashemi          #+#    #+#             #
#   Updated: 2024-09-25 06:19:00 by shashemi         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #
NAME        = libftprintf.a

SRC         = ft_printf.c utils.c #ft_putnbr_fd.c ft_strlen.c ft_putstr_fd.c
BONUSSRC    = 

LIBFT_DIR   = ./libft

LIBFT       = $(LIBFT_DIR)/libft.a

OBJ         = $(SRC:.c=.o)
BONUSOBJ    = $(BONUSSRC:.c=.o)

CC          = cc
CCFLAGS     = -Wall -Wextra -Werror

AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(AR) $(NAME) $(OBJ)
	@$(AR) $(NAME) $(LIBFT_DIR)/*.o

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) all

clean:
	$(RM) $(OBJ) $(BONUSOBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(LIBFT) $(OBJ) $(BONUSOBJ)
	@$(AR) $(NAME) $(OBJ) $(BONUSOBJ)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus