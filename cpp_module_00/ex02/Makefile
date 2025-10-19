NAME = banking.exe

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -pedantic 
VERSION = -std=c++98
CSTAGE = -c

MAIN = tests.cpp
HPP_INCLUDES = Account.hpp
CPP_FILES = Account.cpp

SRCS = $(MAIN) $(CPP_FILES)
OBJECTS = $(SRCS:.cpp=.o)

%.o : %.cpp $(HPP_INCLUDES)
	@echo "compile" $<
	@$(CXX) $(CXXFLAGS) $(VERSION) $(CSTAGE) $< -o $@

all : $(NAME)

$(NAME) : $(OBJECTS)
	@echo "linking" $@ 
	@$(CXX) $(CXXFLAGS) $(VERSION) $^ -o $@


RM = rm
RMFLAGS = -fr
clean :
	$(RM) $(RMFLAGS) $(OBJECTS)


fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all


run : $(NAME)
	@./$(NAME)

.PHONY: all clean fclean run