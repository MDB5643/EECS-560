# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
MAX5H_FILES=$(SRC_FOLDER_MAX5)/max5.mk \
	$(SRC_FOLDER_MAX5)/max5h-data.txt \
	$(SRC_FOLDER_MAX5)/max5h-main.cpp \
	$(SRC_FOLDER_MAX5)/max5-heap.hpp \
	$(SRC_FOLDER_MAX5)/max5-heap.cpp \
	$(SRC_FOLDER_MAX5)/max5h-analyzeBuildHeap.cpp \
	$(SRC_FOLDER_MAX5)/max5h-analyzeMinDelete.cpp \
	$(SRC_FOLDER_MAX5)//max5h-analyzeMaxDelete.cpp \

MAX5_OBJS=$(OUT_LOC)/max5h-main.o  \
	$(OUT_LOC)/max5-heap.o \
	$(OUT_LOC)/max5h-analyzeBuildHeap.o \
	$(OUT_LOC)/max5h-analyzeMinDelete.o \
	$(OUT_LOC)/max5h-analyzeMaxDelete.o \
	$(OUT_LOC)/max5h-main \
	$(OUT_LOC)/max5h-analyzeBuildHeap \
	$(OUT_LOC)/max5h-analyzeMinDelete \
	$(OUT_LOC)/max5h-analyzeMaxDelete \
	$(OUT_LOC)/max5h-data.txt


max5-heap-o:
	$(GCC) $(GCCFLAGS) -c $(SRC_FOLDER_MAX5)/max5-heap.cpp \
		-o $(OUT_LOC)/max5-heap.o

max5h-main:
	$(GCC) $(GCCFLAGS) -c  $(SRC_FOLDER_MAX5)/max5h-main.cpp \
		-o $(OUT_LOC)/max5h-main.o

max5h-build: max5-heap-o max5h-main
	@echo "built object files for max5 heap"

max5h-all: max5h-install max5h-analyze-buildHeap max5h-analyze-min-delete \
	max5h-analyze-max-delete
	@echo "built all executables for max5 heap"

max5h-install: max5h-build
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/max5h-main $(OUT_LOC)/max5-heap.o \
		$(OUT_LOC)/max5h-main.o $(OUT_LOC)/util.o
	cp $(SRC_FOLDER_MAX5)/max5h-data.txt $(OUT_LOC)

max5h-analyze-buildHeap: max5-heap
	@echo "implement the main function to max5h-analyzeBuildHeap element to max5-heap"
	$(GCC) $(GCCFLAGS) -c  $(SRC_FOLDER_MAX5)/max5h-analyzeBuildHeap.cpp \
		-o $(OUT_LOC)/max5h-analyzeBuildHeap.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/max5h-analyzeBuildHeap \
		$(OUT_LOC)/max5h-analyzeBuildHeap.o $(OUT_LOC)/max5-heap.o \
		$(OUT_LOC)/util.o
	./$(OUT_LOC)/max5h-analyzeBuildHeap

max5h-test: max5h-install
	./$(OUT_LOC)/max5h-main

max5h-analyze-min-delete: max5-heap
	@echo "implement the main function to max5h-analyze min delete element to max5-heap"
	$(GCC) $(GCCFLAGS) -c  $(SRC_FOLDER_MAX5)/max5h-analyzeMinDelete.cpp -o $(OUT_LOC)/max5h-analyzeMinDelete.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/max5h-analyzeMinDelete $(OUT_LOC)/max5h-analyzeMinDelete.o $(OUT_LOC)/max5-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/max5h-analyzeMinDelete

max5h-analyze-max-delete: max5-heap
	@echo "implement the main function to max5h-analyze min delete element to max5-heap"
	$(GCC) $(GCCFLAGS) -c  $(SRC_FOLDER_MAX5)/max5h-analyzeMaxDelete.cpp -o $(OUT_LOC)/max5h-analyzeMaxDelete.o
	$(GCC) $(GCCFLAGS) -o $(OUT_LOC)/max5h-analyzeMaxDelete $(OUT_LOC)/max5h-analyzeMaxDelete.o $(OUT_LOC)/max5-heap.o $(OUT_LOC)/util.o
	./$(OUT_LOC)/max5h-analyzeMaxDelete

max5h-clean:
	rm -rf $(MAX5_OBJS)

max5h-debug: max5h-install
	gdb ./$(OUT_LOC)/max5h-main

max5h-mem-check: max5h-install
	valgrind --tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(OUT_LOC)/max5h-main

.PHONY: max5h-clean max5h-all
