NAME = brain.exe

CXX = c++
VERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic
CSTAGE = -c

FILES = main.cpp
SRCS = $(FILES)
OBJS = $(SRCS:.cpp=.o)



RM = rm 
RMFLAGS = -fr 

all : $(NAME)

clean:
	@echo "cleaning" $(OBJS)
	@$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	@echo "cleaning" $(NAME) 
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

run: $(NAME)
	@echo "running " $<
	@./$(NAME)


$(NAME):$(OBJS)
	@echo "linking " $@
	@$(CXX) $(VERSION) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	@echo "compile" $< 
	@$(CXX) $(VERSION) $(CXXFLAGS) $(CSTAGE) $^ -o $@

.PHONY: clean re fclean all run