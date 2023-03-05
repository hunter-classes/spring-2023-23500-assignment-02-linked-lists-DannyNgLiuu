main: main.o list.o node.o olist.o
	g++ -o main main.o list.o node.o olist.o

main.o: main.cpp list.o node.o olist.o
	g++ -c main.cpp

list.o: list.cpp list.h

node.o: node.cpp node.h

olist.o: olist.cpp olist.h

tests: tests.o list.o node.o olist.o
	g++ -o tests tests.o list.o node.o olist.o

tests.o: tests.cpp list.o node.o olist.o
	g++ -c -std=c++11 tests.cpp


clean:
	rm -f main tests main.o tests.o list.o node.o olist.o
