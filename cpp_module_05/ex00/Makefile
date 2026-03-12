NAME = Bureaucrat

CXX = c++
CXXVERSION = -std=c++98

CFLAGS = -Wall -Werror -Wextra -pedantic
MAIN = main.cpp
HEADERS = Bureaucrat.hpp 
SRCS = $(MAIN) Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)


DB_MODE = 0


%.o:%.cpp $(HEADERS)
	@echo "compile" $<
	@$(CXX) $(CXXVERSION) $(CFLAGS) -c $< -o $@ -DDEBUGMODE=$(DB_MODE)




all : $(NAME)


$(NAME) : $(OBJS)
	@echo "linking" $@
	@$(CXX) $(CXXVERSION) $(CFLAGS) $^ -o $@

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
