CLIENT_EXE := client.exe
SERVER_EXE := server.exe
EXE := $(CLIENT_EXE) $(SERVER_EXE)

CLIENT_DIR := ./client/
SERVER_DIR := ./server/

.PHONY: all clean fclean re

all: $(EXE)

$(CLIENT_EXE):
	@echo "Ik ga nu een client maken."
	$(MAKE) --directory $(CLIENT_DIR)
	ln -s $(CLIENT_DIR)$(CLIENT) $(CLIENT)

$(SERVER_EXE):
	@echo "Ik ga nu een server maken."
	$(MAKE) --directory $(SERVER_DIR)
	ln -s $(SERVER_DIR)$(SERVER) $(SERVER)
	
clean:
	$(MAKE) --directory $(CLIENT_DIR) clean
	$(MAKE) --directory $(SERVER_DIR) clean

fclean: clean
	rm $(EXE)
	$(MAKE) --directory $(CLIENT_DIR) fclean
	$(MAKE) --directory $(SERVER_DIR) fclean

re: fclean all
