# please change the XXXX to your username eg. j453h432
STUDENT_ID=XXXXXXX
LAB_NAME=leftist-min-heap-lab-8
GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11


# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
FILES=Makefile priority-queue.hpp priority-queue.cpp \
	application.cpp application.hpp \
	task.hpp task.cpp \
s	scheduler.cpp scheduler.hpp \
	simulator.cpp \
	util.hpp \
	data.txt exp-output-data.txt \
	$(STUDENT_ID)-$(LAB_NAME)-writeup.pdf \
	$(STUDENT_ID)-$(LAB_NAME)-report.pdf

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

install: build
	$(GCC) $(GCCFLAGS) -o simulator simulator.o \
		task.o application.o BinaryNode.o \
		priority-queue.o scheduler.o

build: task application simulator priority-queue BinaryNode scheduler
	@echo "Please use -- make install -- to build executables"
test:
	./simulator

task:
	$(GCC) $(GCCFLAGS) -c task.cpp -o task.o

application:
	$(GCC) $(GCCFLAGS) -c application.cpp -o application.o

BinaryNode:
	$(GCC) $(GCCFLAGS) -c BinaryNode.cpp -o BinaryNode.o

priority-queue:
	$(GCC) $(GCCFLAGS) -c priority-queue.cpp -o priority-queue.o

simulator:
	$(GCC) $(GCCFLAGS) -c simulator.cpp -o simulator.o

scheduler:
	$(GCC) $(GCCFLAGS) -c scheduler.cpp -o scheduler.o

clean:
	rm -rf simulator \
	*.o $(ARCHIVE_FOLDER) *.tar.gz

debug: install
	gdb ./simulator

mem-check: install
	valgrind --tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./simulator
tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
