# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 10:41:42 by joakoeni          #+#    #+#              #
#    Updated: 2024/01/18 10:41:44 by joakoeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= megaphone
CXX				= g++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
SRCS			= megaphone.cpp
OBJS			= $(SRCS:.cpp=.o)

all				: $(NAME)

$(NAME)			: $(OBJS)
					@$(CXX) $(OBJS) -o $(NAME)

%.o				: %.cpp
					$(CXX) $(CXXFLAGS) -o $@ -c $<

clean			:
					rm -rf $(OBJS)

fclean			: clean
					rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
