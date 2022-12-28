LIB_FILES := libft.a\
	libftprintf.a
HDR_FILES := libft.h\
	libftprintf.h

.PHONY: all clean fclean re

all: $(LIB_FILES)
	
libft.a:
	$(MAKE) --directory ./libft/
	ln -fs ./libft/libft.a ./libft.a
	ln -fs ./libft/header/libft.h ./libft.h

libftprintf.a:
	$(MAKE) --directory ./libft/
	ln -fs ./libftprintf/libftprintf.a ./libftprintf.a
	ln -fs ./libftprintf/header/ft_printf.h ./libftprintf.h

clean:
	$(MAKE) --directory ./libft/ clean
	$(MAKE) --directory ./libftprintf/ clean

fclean: clean
	rm $(LIB_FILES)
	$(MAKE) --directory ./libft/ fclean
	$(MAKE) --directory ./libftprintf/ fclean

re: fclean all
