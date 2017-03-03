NAME = filler
BONUS =	bonus
WWW = -Wall -Wextra -Werror
LIB_PATH = libft/
LIBFT = $(LIB_PATH)libft.a
FT_PRINTF_PATH = ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

OBJECTS =	filler.o function.o function_2.o function_3.o function_4.o get_next_line.o function_down_left.o function_down_right.o function_top_left.o function_top_right.o

BON_OBJ = color_output.o get_next_line.o

all: $(NAME)

libft_mc:
	make -C $(LIB_PATH)

ft_printf_mc:
	make -C $(FT_PRINTF_PATH)

filler_obj: $(OBJECTS)

bonus_obj: $(BON_OBJ)

$(NAME): libft_mc ft_printf_mc filler_obj bonus_obj
	gcc $(WWW) -o $(NAME) $(OBJECTS) $(LIBFT) $(FT_PRINTF)
	gcc $(WWW) -o $(BONUS) $(BON_OBJ) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	gcc  $(WWW) -o $@ -c $<

clean:
	make -C $(LIB_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJECTS)
	rm -f $(BON_OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all
