GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11

# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
MINMAXH_FILES=$(SRC_FOLDER_MINMAX)/minmax.mk \
	$(SRC_FOLDER_MINMAX)/minmax-heap.hpp \
	$(SRC_FOLDER_MINMAX)/minmax-heap.cpp \
	$(SRC_FOLDER_MINMAX)/minmaxh-main.cpp \
	$(SRC_FOLDER_MINMAX)/minmaxh-data.txt \
	$(SRC_FOLDER_MINMAX)/minmaxh-analyzeBuildHeap.cpp \
	$(SRC_FOLDER_MINMAX)/minmaxh-analyzeMinDelete.cpp \
	$(SRC_FOLDER_MINMAX)/minmaxh-analyzeMaxDelete.cpp

MINMAX_OBJS=$(OUT_LOC)/minmaxh-main.o \
	$(OUT_LOC)/minmax-heap.o \
	$(OUT_LOC)/minmaxh-analyzeBuildHeap.o \
	$(OUT_LOC)/minmaxh-analyzeMinDelete.o \
	$(OUT_LOC)/minmaxh-analyzeMaxDelete.o \
	$(OUT_LOC)/minmaxh-data.txt \
	$(OUT_LOC)/minmaxh-analyzeBuildHeap \
	$(OUT_LOC)/minmaxh-analyzeMinDelete \
	$(OUT_LOC)/minmaxh-analyzeMaxDelete \
	$(OUT_LOC)/minmaxh-main


ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

.PHONY: minmaxh-clean minmaxh-all

minmaxh-install: minmax-heap-o minmaxh-main
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-main \
	$(OUT_LOC)/minmax-heap.o $(OUT_LOC)/minmaxh-main.o $(OUT_LOC)/util.o
	cp $(SRC_FOLDER_MINMAX)/minmaxh-data.txt $(OUT_LOC)


minmaxh-all: minmaxh-analyze-buildHeap minmaxh-analyze-min-delete minmaxh-analyze-max-delete
	@echo "built all executables"

minmaxh-build: minmaxh-main
	@echo "Please use - make install - to generate executables"

minmaxh-test:
	./$(OUT_LOC)/minmaxh-main

minmax-heap-o:
	$(GCC) $(GCCFLAGS) -c $(SRC_FOLDER_MINMAX)/minmax-heap.cpp -o $(OUT_LOC)/minmax-heap.o

minmaxh-main:
	$(GCC) $(GCCFLAGS) -c $(SRC_FOLDER_MINMAX)/minmaxh-main.cpp -o $(OUT_LOC)/minmaxh-main.o

minmaxh-clean:
	rm -rf $(MINMAX_OBJS)

minmaxh-analyze-buildHeap: minmax-heap
	@echo "implement the main function to minmaxh-analyze build heap element to minmax-heap"
	$(GCC) $(GCCFLAGS) -c $(SRC_FOLDER_MINMAX)/minmaxh-analyzeBuildHeap.cpp -o $(OUT_LOC)/minmaxh-analyzeBuildHeap.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-analyzeBuildHeap $(OUT_LOC)/minmaxh-analyzeBuildHeap.o $(OUT_LOC)/minmax-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/minmaxh-analyzeBuildHeap

minmaxh-analyze-min-delete: minmax-heap
	@echo "implement the main function to minmaxh-analyze min delete element to minmax-heap"
	$(GCC) $(GCCFLAGS) -c $(SRC_FOLDER_MINMAX)/minmaxh-analyzeMinDelete.cpp -o $(OUT_LOC)/minmaxh-analyzeMinDelete.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-analyzeMinDelete $(OUT_LOC)/minmaxh-analyzeMinDelete.o $(OUT_LOC)/minmax-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/minmaxh-analyzeMinDelete

minmaxh-analyze-max-delete: minmax-heap
	@echo "implement the main function to minmaxh-analyze min delete element to minmax-heap"
	$(GCC) $(GCCFLAGS) -c $(SRC_FOLDER_MINMAX)/minmaxh-analyzeMaxDelete.cpp -o $(OUT_LOC)/minmaxh-analyzeMaxDelete.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/minmaxh-analyzeMaxDelete $(OUT_LOC)/minmaxh-analyzeMaxDelete.o $(OUT_LOC)/minmax-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/minmaxh-analyzeMaxDelete

minmaxh-debug: install
	gdb ./$(OUT_LOC)/minmaxh-main

minmaxh-mem-check: install
	valgrind --tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(OUT_LOC)/minmaxh-main
