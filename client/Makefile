# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dbasting <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/28 12:06:53 by dbasting      #+#    #+#                  #
#    Updated: 2022/12/28 16:48:41 by dbasting      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := client

SRC_FILES := client.c
OBJ_FILES := $(SRC_FILES:.c=.o)
HDR_FILES := client.h
LIB_FILES := libft.a\
	libftprintf.a

SRC_DIR := ./source/
OBJ_DIR := ./object/
HDR_DIR := ./header/
LIB_DIR	:= ../lib/

CFLAGS := -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES))
	$(CC) $(CFLAGS) -L$(LIB_DIR) $^ $(addprefix $(LIB_DIR),$(LIB_FILES)) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(addprefix $(HDR_DIR),$(HDR_FILES))
	$(CC) $(CFLAGS) -I$(HDR_DIR) -I$(LIB_DIR) $< -c -o $@

clean:
	rm -f $(OBJ_DIR)*.o
	$(MAKE) --directory=$(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) --directory=$(LIB_DIR) fclean

re: fclean all
