# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Mokefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 21:00:25 by mmaaouni          #+#    #+#              #
#    Updated: 2018/12/10 21:47:32 by mmaaouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = srcs/*.c
OBJECTS = *.o

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBOBJ)
$(OBJECTS): $(FILE)
	gcc -Wall -Wextra -Werror -c $(FILES) -I includes/
clean:
	/bin/rm -f $(OBJECTS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean $(NAME)
