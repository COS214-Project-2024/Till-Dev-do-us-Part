# Compiler and Flags
CXX = g++
CXXFLAGS = -g -Wall -fprofile-arcs -ftest-coverage
LDFLAGS = -fprofile-arcs -ftest-coverage

# Project Files
TARGET = TestingMain
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

# Default Target
all: $(TARGET)

# Link Object Files to Create Executable
$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

# Compile Source Files into Object Files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run with Valgrind
run: $(TARGET)
	valgrind --track-origins=yes --leak-check=full ./$(TARGET)

# Clean Up Build Files
clean:
	rm -f $(OBJECTS) $(TARGET) *.gcda *.gcno *.gcov

# Run Code Coverage Analysis
coverage: $(TARGET)
	./$(TARGET)
	gcov -b $(SOURCES)

# PHONY Targets
.PHONY: all clean run coverage
