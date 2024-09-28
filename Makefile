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

SRC         = ft_printf.c utils.c ft_putnbr_fd.c ft_strlen.c ft_putstr_fd.c
BONUSSRC    = 

OBJ         = $(SRC:.c=.o)
BONUSOBJ    = $(BONUSSRC:.c=.o)

CC          = cc
CCFLAGS     = -Wall -Wextra -Werror

AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ)
	@$(AR) $(NAME) $(OBJ) $(BONUSOBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus