create_hist: create_hist.o
	g++ -o create_hist create_hist.o `root-config --libs`

create_hist.o: create_hist.cxx
	g++ -c `root-config --cflags` create_hist.cxx
