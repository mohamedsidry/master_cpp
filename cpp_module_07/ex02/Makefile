NAME = executable

CXX = c++
CXXVERSION = -std=c++11
CXXFLAGS = -Wall -Werror -Wextra -pedantic

HEADERS = Array.hpp
TEMPLATES = Array.tpp
OBJDIR = objects

SRCS = main.cpp
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))




$(OBJDIR)/%.o:%.cpp $(HEADERS) $(TEMPLATES)
	@mkdir -p $(dir $@)
	@echo $(YELLOW) "Compile : " $(PURPLE) $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	@echo $(YELLOW) "Linking : " $(PURPLE)  $< $(RESET)
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $^ -o $@



clean:
	@echo $(YELLOW) "Clean : " $(PURPLE)  $(OBJS) $(RESET)
	@rm -fr $(OBJDIR)

fclean:
	@echo $(YELLOW) "Full Clean : " $(PURPLE)  $(OBJS) $(NAME) $(RESET)
	@rm -fr  $(OBJDIR) $(NAME)


re : fclean all


all : $(NAME)


run : $(NAME)
	@echo $(YELLOW) "Running : " $(RED) $< $(RESET)
	./$(NAME)


.PHONY: clean fclean run


# COLORS :

RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
PURPLE = "\033[1;34m"
RESET = "\033[0m"