# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Find all .cpp files in the current directory
SOURCES = $(wildcard *.cpp)

# Convert source files to object files
OBJECTS = $(SOURCES:.cpp=.o)

# Main target to build the executable
run: main
	./main
	make clean

# Link all object files into the main executable
main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $(OBJECTS)

# Compile each .cpp file into an .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug build with debug symbols
debug: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -ggdb3 -o main_debug $(OBJECTS)

# Clean command to remove executables and object files
clean:
	rm -f *.o main main_debug

# Valgrind target for memory checks
v: debug
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main_debug
	make clean