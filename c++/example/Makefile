CXX = g++
CXXFLAGS = -Wall -g

main: main.o list.o
	$(CXX) $(CXXFLAGS) -o main main.o list.o

main.o: main.cpp list.h
	$(CXX) $(CXXFLAGS) -c main.cpp

list.o: list.h
	$(CXX) $(CXXFLAGS) -c list.cpp

clean:
	rm *.o main