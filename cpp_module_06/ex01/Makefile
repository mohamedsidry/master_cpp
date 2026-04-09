
NAME=serializer
CXX = c++
CXXVERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic



MAIN = main.cpp
HEADERS = Serializer.hpp data.hpp
SRCS = Serializer.cpp


OBJS = $(MAIN:.cpp=.o) $(SRCS:.cpp=.o)



RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
PURPLE = "\033[1;34m"
RESET = "\033[0m"


%.o:%.cpp $(HEADERS)
	@echo $(YELLOW) " compile :" $(PURPLE) $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@


$(NAME) : $(OBJS)
	@echo $(YELLOW) " linking :" $(PURPLE) $^ $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $^ -o $@

all : $(NAME)


re : fclean all



clean :
	@echo $(YELLOW) " clean :" $(PURPLE) $(OBJS) $(RESET)
	@rm -fr $(OBJS)


fclean : clean
	@echo $(YELLOW) " fclean :" $(PURPLE) $(NAME) $(RESET)
	@rm -fr $(NAME)


.PHONEY: clean
