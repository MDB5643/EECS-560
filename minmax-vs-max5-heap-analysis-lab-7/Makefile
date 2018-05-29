# please change the XXXX to your username eg. j453h432
STUDENT_ID=XXXXXXX
LAB_ID=lab7
LAB_NAME=minmax-vs-max5-heap-$(LAB_ID)
GCC=g++
GCCFLAGS=-Wall -g -pedantic --std=c++11


UTIL_LOC=util
OUT_LOC=out
SRC_FOLDER_MAX5=max5-heap
SRC_FOLDER_MINMAX=minmax-heap

# PLEASE ADD THE NAME OF ALL THE FILES YOU WANT TO GET ARCHIVED
FILES=Makefile \
	$(STUDENT_ID)-minmax-vs-max5-heap-lab7-writeup.pdf \
	$(STUDENT_ID)-minmax-vs-max5-heap-lab7-report.pdf

ARCHIVE_FOLDER=$(STUDENT_ID)-$(LAB_NAME)

include util/util.mk max5-heap/max5.mk minmax-heap/minmax.mk

init:
	@echo "checking if $(OUT_LOC) directory exists"
	if ! [ -d $(OUT_LOC) ]; \
		then mkdir $(OUT_LOC); \
	fi;


all: init util-all max5h-all minmaxh-all
	@echo "built all executables"

install: util-install max5h-install minmaxh-install
	@echo "executables generated in $(OUT_LOC)"

build: util-build max5h-build minmaxh-build
	@echo "Please use  -make install- to generate executables"

clean: max5h-clean minmaxh-clean util-clean
	rm -rf $(ARCHIVE_FOLDER) $(ARCHIVE_FOLDER).tar.gz

analyze-all: install max5h-analyze-buildHeap max5h-analyze-min-delete \
	max5h-analyze-max-delete minmaxh-analyze-buildHeap \
	minmaxh-analyze-min-delete minmaxh-analyze-max-delete

tar: clean
	mkdir $(ARCHIVE_FOLDER)
	cp -rp $(FILES) $(SRC_FOLDER_MINMAX) $(SRC_FOLDER_MAX5) \
		 $(UTIL_LOC) $(ARCHIVE_FOLDER)
	tar cvzf $(ARCHIVE_FOLDER).tar.gz $(ARCHIVE_FOLDER)
	rm -rf $(ARCHIVE_FOLDER)
.PHONY: clean all
