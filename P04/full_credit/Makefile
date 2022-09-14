CXXFLAGS += --std=c++17

all: mcq

mcq: main.o card.o deck.o *.h
	$(CXX) $(CXXFLAGS) main.o card.o deck.o -o mcq
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
card.o: card.cpp *.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o
deck.o: deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
clean:
	rm -f *.o *.gch ~* a.out mcq
