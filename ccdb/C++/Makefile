all: example

example.o: example.cc
	g++ -c -g -I${CCDB_HOME}/include -I/usr/include/mysql example.cc

example: example.o
	g++ -g -o example example.o -L${CCDB_HOME}/lib -lccdb
