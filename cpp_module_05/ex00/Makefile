NAME = Bureaucrat

CXX = c++
CXXVERSION = -std=c++98

CFLASG = -Wall -Werror -Wextra -pedantic
MAIN = main.cpp
HEADERS = Bureaucrat.hpp GradeTooHighException.hpp GradeTooLowException.hpp
SRCS = $(MAIN) Bureaucrat.cpp GradeTooHighException.cpp GradeTooLowException.cpp
OBJS = $(SRCS:.cpp=.o)


%.o:%.cpp $(HEADERS)
	@echo "compile" $<
	@$(CXX) $(CXXVERSION) $(CFLASG) -c $< -o $@



all : $(NAME)


$(NAME) : $(OBJS)
	@echo "linking" $@
	@$(CXX) $(CXXVERSION) $(CFLASG) $^ -o $@

re : fclean all


clean :
	@echo "remove" $(OBJS)
	@rm -fr $(OBJS)

fclean : clean
	@echo "remove" $(NAME)
	@rm -fr $(NAME)



.PHONEY: clean fclean re all run


run : $(NAME)
	@echo "Riunning" $(NAME)
	@./$(NAME)
