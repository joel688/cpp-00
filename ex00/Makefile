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
