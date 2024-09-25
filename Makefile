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

# Nombre del ejecutable o librería a crear
NAME        = libftprintf.a

# Archivos fuente
SRC         = ft_printf.c utils.c
BONUSSRC    = 

# Directorio de la biblioteca libft
LIBFT_DIR   = ./libft

# Nombre de la librería libft
LIBFT      = $(LIBFT_DIR)/libft.a

# Archivos objetos generados a partir de los .c
OBJ         = $(SRC:.c=.o)
BONUSOBJ    = $(BONUSSRC:.c=.o)

# Compilador y flags
CC          = cc
CCFLAGS     = -Wall -Wextra -Werror

# Comando para crear la librería
AR          = ar rcs
RM          = rm -f

# Regla principal (all)
all: $(LIBFT) $(NAME)

# Crear la librería libftprintf.a
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

# Crear los archivos objetos
%.o: %.c
	$(CC) $(CCFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Incluir la librería libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Limpieza de los objetos
clean:
	$(RM) $(OBJ) $(BONUSOBJ)
	@make -C $(LIBFT_DIR) clean

# Limpieza total
fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

# Recompilar todo
re: fclean all

# Recompilar con los bonus
bonus: $(LIBFT) $(OBJ) $(BONUSOBJ)
	@$(AR) $(NAME) $(OBJ) $(BONUSOBJ)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
