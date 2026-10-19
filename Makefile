bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o testListArray testListArray.cpp

clean:
	rm -r *.o *.gch *.pch bin

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o testNode testNode.cpp
