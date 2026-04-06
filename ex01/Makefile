
CXX = c++


CXXFLAGS = -Wall -Wextra -Werror -std=c++98


NAME = Serializer

SRCS = main.cpp Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = ScalarConverter.h Data.h

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

