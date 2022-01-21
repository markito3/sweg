all: example2a button

example2a: example2a.cxx ex2aDict.cxx
	g++ `root-config --cflags --glibs` -o example2a example2a.cxx ex2aDict.cxx
ex2aDict.cxx: example2a.h ex2aLinkDef.h
	rootcint -f ex2aDict.cxx -c example2a.h ex2aLinkDef.h

button: button.cxx buttonDict.cxx otherClass.cxx
	g++ -I. `root-config --cflags --glibs` -lGeom -o button button.cxx buttonDict.cxx otherClass.cxx
buttonDict.cxx: button.h otherClass.h buttonLinkDef.h
	rootcint -f buttonDict.cxx -c button.h otherClass.h buttonLinkDef.h
