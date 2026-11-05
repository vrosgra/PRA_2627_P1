bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o testListArray testListArray.cpp

clean:
	rm -r *.o *.gch *.pch bin

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o testNode testNode.cpp

testListLinked: testListLinked.cpp ListLinked.h Node.h List.h
	mkdir -p bin
	g++ -o testListLinked testListLinked.cpp

point2D.o: point2D.cpp point2D.h
	g++ -c point2D.cpp

testPoint2D: testPoint2D.cpp point2D.o
	g++ -c testPoint2D.cpp
	g++ -o testPoint2D testPoint2D.o point2D.o

Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp


