CFLAGS=-O0 -g -Wall

all: refrigerator

refrigerator.o: refrigerator.cpp refrigerator.h
	g++ $(CFLAGS) -o $(build_dir)/$@ -c refrigerator.cpp

refrigerator: main.cpp  tools.h refrigerator.o
	g++ $(CFLAGS) -o $(build_dir)/$@ main.cpp $(build_dir)/refrigerator.o

.PHONY: all
