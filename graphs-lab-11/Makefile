# please change the XXXXXX to your username eg. j453h432
STUDENT_ID=XXXXXXX
GCC := g++
GCCFLAGS=-Wall -g -pedantic --std=c++11
ARCHIVE_FOLDER := $(STUDENT_ID)-graphs-lab11
FILES=Makefile src test include

SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGET := $(TARGETDIR)/main
HOPELAND := $(TARGETDIR)/hopeland

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -Wall -g -pedantic --std=c++11
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " main Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(GCC) $(GCCFLAGS) $(filter-out $(BUILDDIR)/hopeland.o, $(OBJECTS)) -o $(TARGET)"; \
		$(GCC) $(GCCFLAGS) $(filter-out $(BUILDDIR)/hopeland.o, $(OBJECTS)) -o $(TARGET)

$(HOPELAND): $(OBJECTS)
	@echo " hopland Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(GCC) $(GCCFLAGS) $(filter-out $(BUILDDIR)/main.o, $(OBJECTS)) -o $(HOPELAND)"; \
		$(GCC) $(GCCFLAGS) $(filter-out $(BUILDDIR)/main.o, $(OBJECTS)) -o $(HOPELAND)

test: $(TARGET)
	@echo "Using file from test/data1.txt"
	./$(TARGET) test/data1.txt

test-hopeland: $(HOPELAND)
	@echo "Using file from test/hl-data.txt"
	./$(HOPELAND) test/hl-data.txt

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@cd $(SRCDIR) && `find . -type d -exec mkdir -p ../build/{} \;`;
	@echo " $(GCC)  $(GCCFLAGS) $(CFLAGS) $(INC) -c -o $@ $<"; \
		$(GCC)  $(GCCFLAGS) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGETDIR) $(SRCDIR)"; \
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
