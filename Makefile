

# Target to link object files and create the executable
main: *.o
	g++ -o main *.o 

# Target to compile .cpp files into object files
*.o: *.cpp 
	g++ -c *.cpp 

# Target to run the executable
run: main 
	./main 

# Target to clean up build files
clean: 
	rm *.o main