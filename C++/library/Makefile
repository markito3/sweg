all: program

program: main.o libmy_class.a
	g++ -o program main.o -L. -lmy_class

main.o: main.cc
	g++ -c main.cc

libmy_class.a: my_class_get.o my_class_set.o
	ar -r libmy_class.a my_class_get.o my_class_set.o
%.o: src/%.cc
	g++ -c $<
