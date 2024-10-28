run: main
		./main
		make c

main: *.o
		g++ -std=c++11 -o main *.o

*.o: *.cpp
		g++ -std=c++11 -c -w *.cpp

debugcpp: debugo
		g++ -std=c++11 -ggdb3 -o main *.o

debugo: *.cpp
		g++ -std=c++11 -ggdb3 -c -w *.cpp

c:
		rm *.o main

v: 
		make debugcpp
		valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
		make c