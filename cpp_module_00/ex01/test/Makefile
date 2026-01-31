NAME = test.exe

# COMPLINE & FLAGS
CXX =c++
VERSION = -std=c++98
CSTAGE = -c
CXXFLAGS = -Wall -Werror -Wextra -pedantic

# RESOURCES 

MAIN = test.cpp
CPP_INCLUDES = test.hpp ../includes/const.hpp ../src/models/contact/Contact.hpp ../src/models/phonebook/PhoneBook.hpp ../src/app/PhoneBookApp.hpp ..src/utils/Formatter.hpp ..src/utils/Validator.hpp
CXXFILES = ../src/models/contact/Contact.cpp ../src/models/phonebook/PhoneBook.cpp ../src/app/PhoneBookApp.cpp ../src/utils/Formatter.cpp ../src/utils/Validator.cpp
CXXOBJECTS = $(CXXFILES:.cpp=.o) $(MAIN:.cpp=.o)

# REMOVE 

RM = rm
RMFLAGS = -fr

%.o : %.cpp $(CPP_INCLUDES)
	@echo "compile " $< 
	@$(CXX) $(VERSION) $(CXXFLAGS) $(CSTAGE) $< -o $@


all : $(NAME)


$(NAME) : $(CXXOBJECTS)
	@echo "linking $(NAME)"
	@$(CXX) $(VERSION) $(CXXFLAGS) $^ -o $@
	@echo "successfuly built !"


clean :
	@$(RM) $(RMFLAGS) $(CXXOBJECTS)


fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)



re : fclean all

run : $(NAME) clean
	@clear
	@echo "running $(NAME) ..."
	@./$(NAME)



.PHONY: all clean fclean re run runtest

