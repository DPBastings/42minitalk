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

CLT_NAME := client
SRV_NAME := server
NAME := minitalk

SRC_FILES_COMMON := send.c
OBJ_FILES_COMMON := $(SRC_FILES_COMMON:.c=.o)
HDR_FILES := comm.h
LIB_FILES := libft.a\
	libftprintf.a

SRC_FILES_CLT := $(SRC_FILES_COMMON)\
	client.c
OBJ_FILES_CLT := $(SRC_FILES_CLT:.c=.o)
SRC_FILES_SRV := $(SRC_FILES_COMMON)\
	server.c
OBJ_FILES_SRV := $(SRC_FILES_SRV:.c=.o)

SRC_DIR := ./source/
OBJ_DIR := ./object/
HDR_DIR := ./header/
LIB_DIR	:= ./lib/

CFLAGS := -Wall -Wextra -Werror

.PHONY: $(NAME) all bonus clean fclean lib re

all: lib $(NAME)

lib:
	$(MAKE) --directory=$(LIB_DIR)

$(NAME): $(CLT_NAME) $(SRV_NAME)

$(CLT_NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES_CLT))
	@$(CC) $(CFLAGS) -L$(LIB_DIR) $^ $(addprefix $(LIB_DIR),$(LIB_FILES)) -o $@

$(SRV_NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES_SRV))
	@$(CC) $(CFLAGS) -L$(LIB_DIR) $^ $(addprefix $(LIB_DIR),$(LIB_FILES)) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(addprefix $(HDR_DIR),$(HDR_FILES))
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -I$(LIB_DIR) $< -c -o $@

clean:
	@rm -f $(OBJ_DIR)*.o
	$(MAKE) --directory=$(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) --directory=$(LIB_DIR) fclean

re: fclean all
