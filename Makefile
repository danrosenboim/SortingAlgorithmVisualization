# Define the source files
SRCS := $(wildcard *.cpp)

# Define the object files
OBJS := $(SRCS:.cpp=.o)

# The final binary
main: $(OBJS)
	g++ $(OBJS) -o main -lsfml-graphics -lsfml-window -lsfml-system

# Rule to make the object files
%.o: %.cpp
	g++ -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJS) output

