# please change the XXXX to your username eg. j453h432
STUDENT_ID=XXXXXXX
LAB_NAME=heap-analysis-lab-6
GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11

# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
FILES=Makefile main.cpp min3-heap.hpp min3-heap.cpp \
	util.hpp util.cpp \
	timer.hpp \
	data.txt word-list.txt README.txt\
	analyzeBuildHeap.cpp analyzeMinDelete.cpp \
	analyzeExists.cpp \
	random-word-generator-demo.cpp \
	$(STUDENT_ID)-min3-heap-analysis-writeup.pdf \
	$(STUDENT_ID)-min3-heap-analysis-report.pdf

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

all: install analyze-buildHeap analyze-min-delete analyze-exists
	echo "ran all executables"

install: min3-heap main util
	$(GCC) $(GCCFLAGS) -o main min3-heap.o main.o util.o
build:
	echo "Please use `make install` instead"
test:
	./main

min3-heap:
	$(GCC) $(GCCFLAGS) -c min3-heap.cpp -o min3-heap.o

main:
	$(GCC) $(GCCFLAGS) -c main.cpp -o main.o

util:
	$(GCC) $(GCCFLAGS) -c util.cpp -o util.o

clean:
	rm -rf main analyzeBuildHeap analyzeExists \
	analyzeMinDelete random-word-generator-demo \
	*.o $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

analyze-buildHeap: min3-heap util
	echo "implement the main function to analyze build heap element to min3-heap"
	$(GCC) $(GCCFLAGS) -c analyzeBuildHeap.cpp -o analyzeBuildHeap.o
	$(GCC) $(GCCFLAGS) -o analyzeBuildHeap analyzeBuildHeap.o min3-heap.o util.o
	./analyzeBuildHeap

analyze-min-delete: min3-heap util
	echo "implement the main function to analyze min delete element to min3-heap"
	$(GCC) $(GCCFLAGS) -c analyzeMinDelete.cpp -o analyzeMinDelete.o
	$(GCC) $(GCCFLAGS) -o analyzeMinDelete analyzeMinDelete.o min3-heap.o util.o
	./analyzeMinDelete

analyze-exists: min3-heap util
	echo "implement the main function to analyze max delete element to min3-heap"
	$(GCC) $(GCCFLAGS) -c analyzeExists.cpp -o analyzeExists.o
	$(GCC) $(GCCFLAGS) -o analyzeExists analyzeExists.o min3-heap.o util.o
	./analyzeExists

random-word-generator-demo:
	$(GCC) $(GCCFLAGS) -o random-word-generator-demo random-word-generator-demo.cpp
	./random-word-generator-demo

debug: install
	gdb ./main

mem-check: install
	valgrind --tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./main
tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
