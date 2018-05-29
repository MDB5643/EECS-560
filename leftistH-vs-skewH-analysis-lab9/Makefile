# please change the XXXXXX to your username eg. j453h432
STUDENT_ID=XXXXXXX
GCC := g++
GCCFLAGS=-Wall -g -pedantic --std=c++11
ARCHIVE_FOLDER := $(STUDENT_ID)-leftistH-vs-skewH-analysis-lab9
FILES=Makefile src test include analysis

SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGET := $(TARGETDIR)/simulator
ADDELEM := $(TARGETDIR)/analyzeAddElem
DELETEMIN := $(TARGETDIR)/analyzeMinDelete
CONCAT := $(TARGETDIR)/analyzeConcat

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(filter-out build/simulator/simulator.o, $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o)))
CFLAGS := -Wall -g -pedantic --std=c++11
INC := -I include

$(TARGET): $(OBJECTS) build/simulator/simulator.o
	@echo " Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(GCC) $(GCCFLAGS) $^ -o $(TARGET)"; \
		$(GCC) $(GCCFLAGS) $^ -o $(TARGET)

build/simulator/simulator.o:
	@echo "$(GCC) $(GCCFLAGS) $(INC) -c src/simulator/simulator.cpp -o build/simulator/simulator.o"; \
	$(GCC) $(GCCFLAGS) $(INC) -c src/simulator/simulator.cpp -o build/simulator/simulator.o

analyze: analyze-addElem analyze-deleteMin analyze-concat
	./$(ADDELEM)
	./$(DELETEMIN)
	./$(CONCAT)


analyze-addElem: $(OBJECTS)
	@echo " Building..."
	@mkdir -p build/analysis
	@echo " $(GCC) $(GCCFLAGS) $(INC) -c analysis/analyzeAddElem.cpp -o build/analysis/analyzeAddElem.o"; \
	        $(GCC) $(GCCFLAGS) $(INC) -c analysis/analyzeAddElem.cpp -o build/analysis/analyzeAddElem.o
	@echo " Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(GCC) $(GCCFLAGS) $^ build/analysis/analyzeAddElem.o -o $(ADDELEM)"; \
		$(GCC) $(GCCFLAGS) $^ build/analysis/analyzeAddElem.o -o $(ADDELEM)


analyze-deleteMin: $(OBJECTS)
	@echo " Building..."
	@mkdir -p build/analysis
	@echo " $(GCC) $(GCCFLAGS) $(INC) -c analysis/analyzeDeleteMin.cpp -o build/analysis/analyzeDeleteMin.o"; \
	        $(GCC) $(GCCFLAGS) $(INC) -c analysis/analyzeDeleteMin.cpp -o build/analysis/analyzeDeleteMin.o
	@echo " Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(GCC) $(GCCFLAGS) $^ build/analysis/analyzeDeleteMin.o -o $(DELETEMIN)"; \
		$(GCC) $(GCCFLAGS) $^ build/analysis/analyzeDeleteMin.o -o $(DELETEMIN)


analyze-concat: $(OBJECTS)
	@echo " Building..."
	@mkdir -p build/analysis
	@echo " $(GCC) $(GCCFLAGS) $(INC) -c analysis/analyzeConcat.cpp -o build/analysis/analyzeConcat.o"; \
	        $(GCC) $(GCCFLAGS) $(INC) -c analysis/analyzeConcat.cpp -o build/analysis/analyzeConcat.o
	@echo " Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(GCC) $(GCCFLAGS) $^ build/analysis/analyzeConcat.o -o $(CONCAT)"; \
		$(GCC) $(GCCFLAGS) $^ build/analysis/analyzeConcat.o -o $(CONCAT)


test: $(TARGET)
	@echo "Using file from test/data.txt"
	./bin/simulator test/data.txt

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@cd $(SRCDIR) && `find . -type d -exec mkdir -p ../build/{} \;`;
	@echo " $(GCC)  $(GCCFLAGS) $(CFLAGS) $(INC) -c -o $@ $<"; \
		$(GCC)  $(GCCFLAGS) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGETDIR)"; \
		$(RM) -r $(BUILDDIR) $(TARGETDIR)

tar: clean
	@mkdir -p $(ARCHIVE_FOLDER)
	@cp -r $(FILES) $(ARCHIVE_FOLDER)
	@tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	@rm -rf $(ARCHIVE_FOLDER)

debug: $(TARGET)
	gdb ./$(TARGET)

mem-check: $(TARGET)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all $(TARGET)

.PHONY: clean
