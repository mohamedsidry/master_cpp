NAME = replace.exe

CXX = c++
VERSION = -std=c++98
CXXFLAGS = -Wall -Werror -Wextra -pedantic
CSTAGE = -c


MAIN = main.cpp
CPP_HEADERS = main.hpp Validator.hpp Replace.hpp
CPP_FILES = Validator.cpp Replace.cpp
SRCS = $(MAIN) $(CPP_FILES)

OBJS = $(SRCS:.cpp=.o)




$(NAME) : $(OBJS)
	@echo "linking " $@
	@$(CXX) $(VERSION) $(CXXFLAGS) $(OBJS) -o $@

all : $(NAME)

%.o : %.cpp $(CPP_HEADERS)
	@echo "compling " $<
	@$(CXX) $(VERSION) $(CXXFLAGS) $(CSTAGE) $< -o $@


RM = rm 
RMFLAGS = -fr 


clean:
	@echo "cleaning " $(OBJS)
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@echo "cleaning " $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

run : $(NAME)
	@echo "running " $(NAME)
	@read -p "Enter infile : " infile;\
	read -p "Enter string to be replaced : " toreplace;\
	read -p "Enter new string : " newstr; \
	./$(NAME) "$$infile" "$$toreplace" "$$newstr"; \
	status=$$?; \
	echo "$(NAME)" "exited with : " "$$status"

# infile=infile
# target=target
# newstr=neswtr
# runtest : $(NAME)
# 	echo $(NAME) $(infile) $(target) $(newstr)
# 	@./$(NAME) $(infile) $(target) $(newstr)

.PHONY: all clean fclean re run
