NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -pedantic
CXXVERSION = -std=c++98

OBJS_DIR = build

HPP = PmergeMe.hpp 


SRCS =	main.cpp PmergeMe.cpp 

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)


RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;34m
RESET = \033[0m

RM = rm
RMFLAGS = -rf

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(YELLOW)Building: $(PURPLE)%s$(RESET)\n" $@
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) $(OBJS) -o $@


$(OBJS_DIR)/%.o: %.cpp $(HPP)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling: $(PURPLE)%s$(RESET)\n" $<
	@$(CXX) $(CXXVERSION) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	@printf "$(YELLOW)Cleaning object files: $(PURPLE)%s$(RESET)\n" $(OBJS)
	@$(RM) $(RMFLAGS) $(OBJS_DIR)


fclean: clean
	@printf "$(YELLOW)Removing executable: $(PURPLE)%s$(RESET)\n" $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all

R=1-100000
N=3000

run : $(NAME)
	@printf "$(YELLOW)Running $(PURPLE)%s$(RESET)\n" $(NAME)
	@./$(NAME)  `shuf -i $(R) -n $(N) | tr "\n" " "`

.PHONY: all clean fclean re