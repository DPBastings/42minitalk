define execute
$(1)

endef

EXE_FILES := client server
EXE_DIRS := $(EXE_FILES:%=./%/)
EXE_PATH := $(foreach f,$(EXE_FILES),$(addprefix ./$(f)/,$(f)))
LIB_DIR := ./lib/

.PHONY: all clean fclean lib re

all: lib
	$(foreach f,$(EXE_DIRS),$(call execute,$(MAKE) --directory=$(f)))
	$(foreach e,$(EXE_PATH),$(call execute,@ln -fs $(e) $(addsuffix .exe,$(notdir $(e)))))

lib:
	$(MAKE) --directory=$(LIB_DIR)
	
clean:
	$(MAKE) --directory=$(LIB_DIR) clean
	$(foreach p,$(EXE_DIRS),$(call execute,$(MAKE) --directory=$(p) clean))

fclean: clean
	@rm -f *.exe
	$(MAKE) --directory $(LIB_DIR) clean
	$(foreach p,$(EXE_DIRS),$(call execute,$(MAKE) --directory=$(p) fclean))

re: fclean all
