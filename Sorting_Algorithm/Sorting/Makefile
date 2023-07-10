all: main.o Sorting.o ../ArrayList/ArrayList.o
	g++ main.o Sorting.o ../ArrayList/ArrayList.o -o Sorting
	./Sorting
	rm -f *.o ../ArrayList/ArrayList.o Sorting

main.o: main.cpp
	g++ -c main.cpp -o main.o -g

Sorting.o: Sorting.cpp
	g++ -c Sorting.cpp -o Sorting.o -g

../ArrayList/ArrayList.o: ../ArrayList/ArrayList.cpp
	g++ -c ../ArrayList/ArrayList.cpp -o ../ArrayList/ArrayList.o -g

clean:
	rm -f *.o ../ArrayList/ArrayList.o Sorting