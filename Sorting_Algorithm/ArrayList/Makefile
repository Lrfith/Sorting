# Link
all: main.o ArrayList.o
	g++ main.o ArrayList.o -o ArrayList -g
	./ArrayList
	rm -f *.o ArrayList

# Compile
main.o: main.cpp
	g++ -c main.cpp -o main.o -g

ArrayList.o: ArrayList.cpp
	g++ -c ArrayList.cpp -o ArrayList.o -g

# Clean
clean:
	rm -f *.o ArrayList

# <target>: <prerequisites> 
# 		<command>