CLIENT_EXE := client
SERVER_EXE := server
EXE := $(CLIENT_EXE) $(SERVER_EXE)

CLIENT_DIR := ./client/
SERVER_DIR := ./server/

.PHONY: all $(addprefix $(CLIENT_DIR),$(CLIENT_EXE)) $(addprefix $(SERVER_DIR),$(SERVER_EXE)) clean fclean re

all: $(addprefix $(CLIENT_DIR),$(CLIENT_EXE)) $(addprefix $(SERVER_DIR),$(SERVER_EXE))

$(addprefix $(CLIENT_DIR),$(CLIENT_EXE)):
	@$(MAKE) --directory $(CLIENT_DIR)
	@ln -fs $@ $(addsuffix .exe,$(CLIENT_EXE))

$(addprefix $(SERVER_DIR),$(SERVER_EXE)):
	@$(MAKE) --directory $(SERVER_DIR)
	@ln -fs $@ $(addsuffix .exe,$(SERVER_EXE))
	
clean:
	@$(MAKE) --directory $(CLIENT_DIR) clean
	@$(MAKE) --directory $(SERVER_DIR) clean

fclean: clean
	@rm -f $(addsuffix .exe,$(EXE))
	@$(MAKE) --directory $(CLIENT_DIR) fclean
	@$(MAKE) --directory $(SERVER_DIR) fclean

re: fclean all
