OBJECTS=List.o Node.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o
	$(CXX) -o main main.o $(OBJECTS)

tests: tests.o List.o Node.o
	$(CXX) -o tests tests.o $(OBJECTS)

main.o: main.cpp List.h

tests.o: tests.cpp List.h doctest.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS) main tests main.o tests.o
