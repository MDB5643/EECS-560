# please change the XXXX to your username eg. j453h432
STUDENT_ID=XXXXXXX
LAB_NAME=binary-tree-lab-4
GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11

# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
FILES=Makefile main.cpp util.hpp data.txt \
	binary-tree.hpp binary-tree.cpp \
	$(STUDENT_ID)-writeup.pdf

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

install: binary-tree Queue BinaryNode main
	$(GCC) $(GCC_FLAGS) -o main main.o Queue.o BinaryNode.o binary-tree.o

binary-tree:
	$(GCC) $(GCCFLAGS) -c binary-tree.cpp -o binary-tree.o

Queue:
	$(GCC) $(GCCFLAGS) -c Queue.cpp -o Queue.o

Node:
	$(GCC) $(GCCFLAGS) -c Node.cpp -o Node.o

BinaryNode:
	$(GCC) $(GCCFLAGS) -c BinaryNode.cpp -o BinaryNode.o

test: install
	./main

main:
	$(GCC) $(GCCFLAGS) -c main.cpp -o main.o

clean:
	rm -rf main *.o $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
