CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = identify

SRCS = main.cpp Base.cpp generate.cpp identify.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Base.h A.h B.h C.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

