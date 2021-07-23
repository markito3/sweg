all: program_static program_shared

program_static: main.o libmy_class_static.a
	g++ -o program_static main.o -L. -lmy_class_static

program_shared: main.o libmy_class_shared.so
	g++ -o program_shared main.o -L. -lmy_class_shared

main.o: main.cc
	g++ -c main.cc

libmy_class_static.a: my_class_get.o my_class_set.o
	ar -r libmy_class_static.a my_class_get.o my_class_set.o

libmy_class_shared.so: my_class_get.o my_class_set.o
	g++ -shared -o libmy_class_shared.so my_class_get.o my_class_set.o

%.o: src/%.cc
	g++ -c $<
