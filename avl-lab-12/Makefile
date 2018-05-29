# please change the XXXX to your username eg. j453h432
STUDENT_ID=XXXXXXX
LAB_NAME=avl-lab12
GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11

# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
FILES=Makefile library.cpp avl.hpp avl.cpp \
	book.cpp book.hpp \
	catalog.cpp catalog.hpp \
	util.hpp \
	data.txt \
	$(STUDENT_ID)-avl-writeup.pdf

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

install: build
	@echo "Linking.. "
	@echo "$(GCC) $(GCCFLAGS) -o library avl.o library.o book.o catalog.o"
	$(GCC) $(GCCFLAGS) -o library avl.o BinaryNode.o library.o book.o catalog.o

build: avl library catalog book BinaryNode
	@echo "Building.. "

test:
	./library
avl:
	$(GCC) $(GCCFLAGS) -c avl.cpp -o avl.o

BinaryNode:
	$(GCC) $(GCCFLAGS) -c BinaryNode.cpp -o BinaryNode.o

book:
	$(GCC) $(GCCFLAGS) -c book.cpp -o book.o

catalog: avl book
	$(GCC) $(GCCFLAGS) -c catalog.cpp -o catalog.o

library: catalog
	$(GCC) $(GCCFLAGS) -c library.cpp -o library.o

clean:
	rm -rf library *.o $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

debug: install
	gdb ./library

mem-check: install
	valgrind --tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./library

tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
