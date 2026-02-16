CC = c++
FLAG = -Wextra -Werror -Wall -std=c++98
SOURCE = helperfunction/HelperString.cpp mainprocess/main.cpp response/clsResponse.cpp response/clsErrorPage.cpp \

HEADERS = response/clsResponse.hpp response/clsResponse.hpp mainprocess/librarys.hpp mainprocess/clsMainProcess.hpp \
	mainprocess/Webserv.hpp 
OBJ = $(SOURCE:.cpp=.o)
EXECUTE = webserv
all :$(EXECUTE)
$(EXECUTE) : $(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $@
	@echo "compiling..."
%.o:%.cpp $(HEADERS)
	@$(CC) $(FLAG) -c $< -o $@
clean:
	@echo "cleaning up..."
	@rm -rf $(OBJ)
fclean: clean
	@echo "removing ..."
	@rm -rf $(EXECUTE)
re : fclean all