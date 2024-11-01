main:
	g++ -g -std=c++11 *.cpp -o main

run:
	./main

clean:
	rm *.o

all:
	make -s && make run -s