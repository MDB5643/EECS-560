STUDENT_ID=2636836
LAB_NAME=lab02
GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11

FILES=Makefile main.cpp list.hpp list.cpp data.txt doubleNode.hpp doubleNode.cpp timer.hpp\
	analyzeAdd.cpp analyzeDelete.cpp analyzeGetPositionList.cpp sparse-matrix.cpp sparse-matrix.hpp util.hpp analyzeEquals.cpp analyzeTranspose.cpp

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

build: list main doubleNode
	$(GCC) $(GCCFLAGS) -o main list.o main.o doubleNode.o

build-matrix: list
	$(GCC) $(GCCFLAGS) -c sparse-matrix.cpp -o sparse-matrix.o

test:
	./main

doubleNode:
	$(GCC) $(GCCFLAGS) -c doubleNode.cpp -o doubleNode.o

list: list.hpp doubleNode
	$(GCC) $(GCCFLAGS) -c list.cpp -o list.o

main:
	$(GCC) $(GCCFLAGS) -c main.cpp -o main.o

sparse-matrix: list
	$(GCC) $(GCCFLAGS) -c sparse-matrix.cpp -o sparse-matrix.o

clean:
	rm -rf main *.o rm $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

analyze-add-tail: clean list doubleNode
	echo "implement the main function to analyze add at tail"
	$(GCC) $(GCCFLAGS) -c analyzeAdd.cpp -o analyzeAdd.o
	$(GCC) $(GCCFLAGS) -o analyzeAdd analyzeAdd.o list.o doubleNode.o
	./analyzeAdd

analyze-delete: clean list doubleNode
	echo "implement the main function to analyze delete"
	$(GCC) $(GCCFLAGS) -c analyzeDelete.cpp -o analyzeDelete.o
	$(GCC) $(GCCFLAGS) -o analyzeDelete analyzeDelete.o list.o doubleNode.o
	./analyzeDelete

analyze-getPositionList: clean list doubleNode
	echo "implement the main function to analyze getPostionList"
	$(GCC) $(GCCFLAGS) -c analyzeGetPositionList.cpp -o analyzeGetPositionList.o
	$(GCC) $(GCCFLAGS) -o analyzeGetPositionList analyzeGetPositionList.o list.o doubleNode.o
	./analyzeGetPositionList

analyze-equals: clean sparse-matrix doubleNode
	echo "implement the main function to analyze equals on sparse-matrix"
	$(GCC) $(GCCFLAGS) -c analyzeEquals.cpp -o analyzeEquals.o
	$(GCC) $(GCCFLAGS) -o analyzeEquals analyzeEquals.o list.o sparse-matrix.o doubleNode.o
	./analyzeEquals

analyze-transpose: clean sparse-matrix doubleNode
	echo "implement the main function to analyze transpose on sparse-matrix"
	$(GCC) $(GCCFLAGS) -c analyzeTranspose.cpp -o analyzeTranspose.o
	$(GCC) $(GCCFLAGS) -o analyzeTranspose analyzeTranspose.o sparse-matrix.o list.o doubleNode.o
		./analyzeTranspose

tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
