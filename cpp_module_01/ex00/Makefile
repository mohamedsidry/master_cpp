NAME = Brainz.exe

CXX = c++
VERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic
CSTAGE = -c

HPP_INCLUDES = Zombie.hpp
MAIN = main.cpp
CPP_FILES = Zombie.cpp newZombie.cpp randomChump.cpp
SRCS = $(MAIN) $(CPP_FILES)
OBJECTS = $(SRCS:.cpp=.o)



%.o : %.cpp $(HPP_INCLUDES)
	@echo "compile " $<
	@$(CXX) $(VERSION) $(CXXFLAGS) $(CSTAGE) $< -o $@

all : $(NAME)


$(NAME) : $(OBJECTS)
	@echo "linking " $@
	@$(CXX) $(VERSION) $(CXXFLAGS) $^ -o $@


RM = rm 
RMFLAGS = -fr


clean :
	@echo "remove" $(OBJECTS)
	@$(RM) $(RMFLAGS) $(OBJECTS)


fclean: clean
	@echo "remove" $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)


re : fclean all


run : $(NAME)
	@echo "running " $<
	@./$(NAME)


.PHONY: all clean fclean re run