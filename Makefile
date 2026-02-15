CC = c++
FALG = -Wextra -Werror -Wall -std=c++98
SOURCE = helperfunction/HelperString.cpp mainprocess/main.cpp /
		response/clsResponse.cpp response/clsErrorPage.cpp
HEADERS = response/clsResponse.hpp response/clsResponse.hpp mainprocess/librarys.hpp /
			mainprocess/clsMainProcess.hpp mainprocess/Webserv.hpp
OBJ = $(SOURCE:.cpp=.o)
EXECUTE = webserv

$(EXECUTE) : $(OBJ)
	$(CC) $(FLAG) $< -o $@
%.o:%.cpp $(HEADERS)
	$(CC) $(FLAG) -c $< -o $@
clean:
	rm -rf $