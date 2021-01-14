all: example

example.o: example.cc
	g++ -c -I${CCDB_HOME}/include -I/usr/include/mysql example.cc

example: example.o
	g++ -o example example.o -L${CCDB_HOME}/lib -lccdb
