main:
	g++ -g -std=c++0x *.cpp  -o main

run:
	./main

clean:
	rm main

all:
	make -s && make run -s