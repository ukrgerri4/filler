# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:53:26 by ikryvenk          #+#    #+#              #
#    Updated: 2017/02/07 16:08:49 by ikryvenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
WWW = -Wall -Wextra -Werror
LIB_PATH = ../libft/
LIBFT = $(LIB_PATH)libft.a

OBJECTS = ft_checkparam.o ft_checkparam_fun.o ft_p_numb.o ft_p_string.o ft_printf.o ft_put_count.o ft_types.o ft_p_wstring.o ft_p_wput_count.o ft_p_wstring2.o

all: $(NAME)

libmc:
	make -C $(LIB_PATH)

$(NAME): libmc $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBFT)

%.o: %.c
	gcc  $(WWW) -o $@ -c $<

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB_PATH) $(LIBFT)
	rm -f $(NAME)

re: fclean all
