CFLAGS=-O0 -g -Wall -std=c++11

all: refrigerator

refrigerator.o: refrigerator.cpp refrigerator.h
	g++ $(CFLAGS) -o $(build_dir)/$@ -c refrigerator.cpp

test.o: test.cpp test.h refrigerator.o
	g++ $(CFLAGS) -o $(build_dir)/$@ -c test.cpp

refrigerator: main.cpp  tools.h test.o
	g++ $(CFLAGS) -o $(build_dir)/$@ main.cpp $(build_dir)/*.o

.PHONY: all
