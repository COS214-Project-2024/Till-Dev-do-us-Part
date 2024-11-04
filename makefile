main:
	g++ -g -std=c++0x *.cpp -o main

run:
	./main

clean:
	rm main

all:
	make -s && make run -s

# CXX := g++
# CXXFLAGS := -g -std=c++11 -Wall -pedantic
# INCLUDE_PATH := include
# SOURCES := $(wildcard src/*.cpp)
# OBJECTS := $(SOURCES:.cpp=.o)
# MAIN := Testingmain.cpp

# .PHONY: all run clean

# all: $(OBJECTS)
# 	$(CXX) $^ -o main

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -I$(INCLUDE_PATH) -c $< -o $@

# run:
# 	./main

# clean:
# 	rm -f *.o main
