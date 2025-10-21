NAME = humanAttack.exe

CXX = c++
VERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic
CSTAGE = -c


MAIN = main.cpp
CPP_HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp
CPP_FILES = Weapon.cpp HumanA.cpp HumanB.cpp
SRCS = $(MAIN) $(CPP_FILES)

OBJS = $(SRCS:.cpp=.o)




$(NAME) : $(OBJS)
	@echo "linking " $@
	@$(CXX) $(VERSION) $(CXXFLAGS) $(OBJS) -o $@

all : $(NAME)

%.o : %.cpp $(CPP_HEADERS)
	@echo "compling " $<
	@$(CXX) $(VERSION) $(CXXFLAGS) $(CSTAGE) $< -o $@


RM = rm 
RMFLAGS = -fr 


clean:
	@echo "cleaning " $(OBJS)
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@echo "cleaning " $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all


run : $(NAME)
	@echo "running " $(NAME)
	@./$(NAME)


.PHONY: all clean fclean re run
