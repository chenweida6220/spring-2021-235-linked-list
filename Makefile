OBJECTS=List.o Node.o DList.o DNode.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o DList.o DNode.o
	$(CXX) -o main main.o $(OBJECTS)

tests: tests.o List.o Node.o DList.o DNode.o
	$(CXX) -o tests tests.o $(OBJECTS)

main.o: main.cpp List.h DList.h

tests.o: tests.cpp List.h DList.h doctest.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

DList.o: DList.cpp DList.h DNode.h

DNode.o: DNode.cpp DNode.h

clean:
	rm -f $(OBJECTS) main tests main.o tests.o DList.o DNode.o

help:
	echo "hi"
