NAME = executable

CXX = c++
CXXVERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic


MAIN = main.cpp
HEADERS = whatever.hpp

OBJS = $(MAIN:.cpp=.o)


RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
PURPLE = "\033[1;34m"
RESET = "\033[0m"


%.o:%.cpp $(HEADERS)
	@echo $(YELLOW) "Compile : " $(PURPLE) $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@



$(NAME) : $(OBJS)
	@echo $(YELLOW) "Linking : " $(PURPLE) $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $^ -o $@



clean : 
	@echo $(YELLOW) "Clean : " $(PURPLE) $(OBJS) $(RESET)
	@rm -fr $(OBJS)


fclean : clean
	@echo $(YELLOW) "FClean : " $(PURPLE) $(NAME) $(RESET)
	@rm -fr $(NAME)


re : fclean all

all : $(NAME)


.PHONY: clean




