# COMPILE FLAGS
NAME = megaphone.exe
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra
CSTAGE = -c
VERSION = -std=c++98

# RESOURCES
CPP_HEADERS = 
CPP_FILES = megaphone.cpp
CPP_OBJECTS = $(CPP_FILES:.cpp=.o)

RM = rm 
RMFLAGS = -fr

# BUILD OBJECTS
%.o : %.cpp $(CPP_HEADERS)
	@echo "compile " $<
	@$(CXX) $(CXXFLAGS) $(VERSION) $(CSTAGE) $< -o $@

# LINK OBJECTS

$(NAME) : $(CPP_OBJECTS)
	@echo "linking " $^
	@$(CXX) $(CXXFLAGS) $(VERSION) $^ -o $(NAME)

all : $(NAME)


clean :
	@echo "Remove" $(OBJECTS)
	@$(RM) $(RMFLAGS) $(CPP_OBJECTS)


fclean : clean
	@echo "Remove" $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all
	@echo "Rebuild" $(NAME)

run: $(NAME)
	@echo "Running" $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re run
