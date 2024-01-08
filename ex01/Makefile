NAME		=			phonebook

CXX			=			g++
CXXFLAGS	=			-Wall -Wextra -Werror -std=c++98 -Iincludes/

SRCS		=			sources/main.cpp\

HDRS		=			includes/PhoneBook.hpp\

OBJS		=			$(SRCS:.cpp=.o)

all			:			$(NAME)

$(NAME)		:			$(OBJS) $(HDRS)
						$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean		:
						rm -rf $(OBJS)

fclean		:			clean
						rm -rf $(NAME)

re			:			fclean all

.PHONY		:			all clean fclean re
