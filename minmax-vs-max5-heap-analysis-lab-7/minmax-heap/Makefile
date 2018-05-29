GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11

UTIL_LOC=../util
OUT_LOC=../out

# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
FILES=Makefile minmaxh-main.cpp minmax-heap.hpp minmax-heap.cpp \
	data.txt \
	minmaxh-analyzeBuildHeap.cpp minmaxh-analyzeMinDelete.cpp \
	minmaxh-analyzeMaxDelete.cpp

OBJS=$(OUT_LOC)/minmaxh-main.o $(OUT_LOC)/minmax-heap.o \
	$(OUT_LOC)/minmaxh-analyzeBuildHeap.o $(OUT_LOC)/minmaxh-analyzeMinDelete.o \
	$(OUT_LOC)/minmaxh-analyzeMaxDelete.o

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

.PHONY: clean all


install: init minmax-heap minmaxh-main
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-main $(OUT_LOC)/minmax-heap.o $(OUT_LOC)/minmaxh-main.o $(OUT_LOC)/util.o

init:
	@echo "checking if $(OUT_LOC) directory exists"
	if ! [ -d $(OUT_LOC) ]; \
		then mkdir $(OUT_LOC); \
	fi;

all: install minmaxh-analyze-buildHeap minmaxh-analyze-min-delete minmaxh-analyze-max-delete
	@echo "built all executables"

build: init minmaxh-main
	@echo "Please use `make install` to generate executables"

test:
	./$(OUT_LOC)/minmaxh-main

minmax-heap:
	$(GCC) $(GCCFLAGS) -c minmax-heap.cpp -o $(OUT_LOC)/minmax-heap.o

minmaxh-main:
	$(GCC) $(GCCFLAGS) -c minmaxh-main.cpp -o $(OUT_LOC)/minmaxh-main.o

clean:
	rm -rf $(OBJS)

minmaxh-analyze-buildHeap: minmax-heap
	@echo "implement the main function to minmaxh-analyze build heap element to minmax-heap"
	$(GCC) $(GCCFLAGS) -c minmaxh-analyzeBuildHeap.cpp -o $(OUT_LOC)/minmaxh-analyzeBuildHeap.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-analyzeBuildHeap $(OUT_LOC)/minmaxh-analyzeBuildHeap.o $(OUT_LOC)/minmax-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/minmaxh-analyzeBuildHeap

minmaxh-analyze-min-delete: minmax-heap
	@echo "implement the main function to minmaxh-analyze min delete element to minmax-heap"
	$(GCC) $(GCCFLAGS) -c minmaxh-analyzeMinDelete.cpp -o $(OUT_LOC)/minmaxh-analyzeMinDelete.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-analyzeMinDelete $(OUT_LOC)/minmaxh-analyzeMinDelete.o $(OUT_LOC)/minmax-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/minmaxh-analyzeMinDelete

minmaxh-analyze-max-delete: minmax-heap
	@echo "implement the main function to minmaxh-analyze min delete element to minmax-heap"
	$(GCC) $(GCCFLAGS) -c minmaxh-analyzeMaxDelete.cpp -o $(OUT_LOC)/minmaxh-analyzeMaxDelete.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-analyzeMaxDelete $(OUT_LOC)/minmaxh-analyzeMaxDelete.o $(OUT_LOC)/minmax-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/minmaxh-analyzeMaxDelete

debug: install
	gdb ./$(OUT_LOC)/minmaxh-main

mem-check: install
	valgrind --tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(OUT_LOC)/minmaxh-main
tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -r $(FILES) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
