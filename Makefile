CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC := ft_printf.c ft_putnbr.c ft_putchr.c ft_putstr.c ft_puthexa.c ft_putunsdec.c

NAME := libftprintf.a

HEADER := ft_printf.h

OBJ := $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : clean fclean all

.PHONY : all clean fclean re