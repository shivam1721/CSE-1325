CXXFLAGS += --std=c++17

all: smart

smart: person.o student.o parent.o main.o *.h
	$(CXX) $(CXXFLAGS) person.o student.o parent.o main.o  -o smart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) person.cpp -c -o person.o
	
student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) student.cpp -c -o student.o
	
parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) parent.cpp -c -o parent.o

debug: CXXFLAGS += g
degub: smart	
		
clean:
	rm -f *.o *.gch a.out smart
