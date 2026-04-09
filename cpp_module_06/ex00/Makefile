NAME = convert

CXX = c++
CXXVERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic

MAIN = main.cpp
HEADERS = ScalarConverter.hpp
SRCS = ScalarConverter.cpp
OBJS = $(MAIN:.cpp=.o) $(SRCS:.cpp=.o)

%.o:%.cpp $(HEADERS)
	@echo "compile" $<
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@



$(NAME) : $(OBJS)
	@echo "linking" $^
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $(OBJS) -o $@




all : $(NAME)



re : fclean all


clean : 
	@echo "removing" $(OBJS)
	@rm -fr $(OBJS)


fclean : clean
	@echo "removing" $(NAME)
	@rm -fr $(NAME)



test : $(NAME)
	@./tester.sh

.PHONEY: clean




