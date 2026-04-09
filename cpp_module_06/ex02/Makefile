NAME = typeinfo


CXX = c++
CXXVERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic
MAIN = main.cpp
HEADERS = Base.hpp A.hpp B.hpp C.hpp 
SRCS = Base.cpp A.cpp B.cpp C.cpp 
objs = $(MAIN:.cpp=.o) $(SRCS:.cpp=.o)

# COLORS :

RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
PURPLE = "\033[1;34m"
RESET = "\033[0m"

%.o:%.cpp $(HEADERS)
	@echo $(YELLOW) "Compile : " $(PURPLE) $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@



$(NAME) : $(objs)
	@echo $(YELLOW) "Linking : " $(PURPLE) $@ $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $(objs) -o $@


all : $(NAME)


clean:
	@echo $(YELLOW) "Cleaning : " $(PURPLE) $(objs) $(RESET)
	@rm -fr $(objs)

fclean: clean
	@echo $(YELLOW) "Cleaning : " $(PURPLE) $(NAME) $(RESET)
	@rm -fr $(NAME)


re : fclean all


run : $(NAME)
	@echo $(YELLOW) "Running : " $(RED) $(NAME) $(RESET)
	@./$(NAME)

.PHONEY: clean
