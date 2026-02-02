NAME = a.out

CXX = c++
CXXVERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic
CXXSTAGE = -c

CXXHEADERS = AAnimal.hpp Dog.hpp Cat.hpp Brain.hpp
CXXMAIN = main.cpp 
CXXSRC = AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
CXXOBJS = $(CXXMAIN:.cpp=.o)  $(CXXSRC:.cpp=.o)


all : $(NAME)

$(NAME) : $(CXXOBJS)
	@echo "linking" $@
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $(CXXOBJS) -o $@


RM = rm
RMFLAGS = -fr 

clean :
	@echo "remove" $(CXXOBJS)
	@$(RM) $(RMFLAGS) $(CXXOBJS)


fclean : clean
	@echo "remove" $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)


re : clean all



%.o : %.cpp $(CXXHEADERS)
	@echo "compile" $<
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $(CXXSTAGE) $< -o $@


run : $(NAME)
	@echo "running " $<
	@./$<

.PHONY: clean re fclean all run