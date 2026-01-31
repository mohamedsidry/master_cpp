NAME = phonebook.exe

# COMPLINE & FLAGS
CXX =c++
VERSION = -std=c++98
CSTAGE = -c
CXXFLAGS = -Wall -Werror -Wextra -pedantic

# RESOURCES 

MAIN = main.cpp
CPP_INCLUDES = includes/const.hpp includes/main.hpp src/models/contact/Contact.hpp src/models/phonebook/PhoneBook.hpp src/app/PhoneBookApp.hpp src/utils/Formatter.hpp src/utils/Validator.hpp
CXXFILES = src/models/contact/Contact.cpp src/models/phonebook/PhoneBook.cpp src/app/PhoneBookApp.cpp src/utils/Formatter.cpp src/utils/Validator.cpp

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
	@echo "cleaning $(CXXOBJECTS)"
	@$(RM) $(RMFLAGS) $(CXXOBJECTS)


fclean : clean
	@echo "cleaning $(NAME)"
	@$(RM) $(RMFLAGS) $(NAME)



re : fclean all

run : $(NAME) clean
	@echo "running $(NAME) ..."
	@./$(NAME)



runtest : 
	@make -C test/ run --no-print-directory
	@make  -C test/ clean --no-print-directory



.PHONY: all clean fclean re run runtest

