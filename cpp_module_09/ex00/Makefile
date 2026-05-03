NAME = btc

CXX = c++
CXXVERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic



MAIN = main.cpp
SRCS =  $(MAIN) BitcoinExchange.cpp
OBJDIR = build
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))
HPP = BitcoinExchange.hpp

RM = rm
RMFLAGS = -fr



$(OBJDIR)/%.o:%.cpp $(HPP)
	@mkdir -p $(dir $@)
	@echo $(YELLOW) "Compile : " $(PURPLE) $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@



$(NAME) : $(OBJS)
	@echo $(YELLOW) "Linking : " $(PURPLE) $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $(OBJS) -o $@



all : $(NAME)


clean :
	@echo $(YELLOW) "Cleaning : " $(PURPLE) $(OBJS) $(RESET)
	@$(RM) $(RMFLAGS) $(OBJDIR)

fclean :
	@echo $(YELLOW) "Full Cleaning : " $(PURPLE) $(OBJS) $(NAME) $(RESET)
	@$(RM) $(RMFLAGS) $(OBJDIR) $(NAME)

re : fclean all



FILE = input.txt
run : $(NAME)
	@echo $(YELLOW) "Running : " $(PURPLE) $< $(RESET)
	@./$(NAME) $(FILE)




test :
	make runtest -C test/


.PHONY: clean run test






RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
PURPLE = "\033[1;34m"
RESET = "\033[0m";