LIB_FILES := libft.a\
	libftprintf.a

.PHONY: all $(LIB_FILES) clean fclean re

all: $(LIB_FILES)
	
libft.a:
	$(MAKE) --directory ./libft/
	ln -fs ./libft/libft.a ./libft.a

libftprintf.a:
	$(MAKE) --directory ./libftprintf/
	ln -fs ./libftprintf/libftprintf.a ./libftprintf.a

clean:
	$(MAKE) --directory ./libft/ clean
	$(MAKE) --directory ./libftprintf/ clean

fclean: clean
	rm -f $(LIB_FILES)
	$(MAKE) --directory ./libft/ fclean
	$(MAKE) --directory ./libftprintf/ fclean

re: fclean all
