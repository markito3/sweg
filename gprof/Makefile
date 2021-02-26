all: display

hog: hog.f
	gfortran -pg hog.f -o hog

gmon.out: hog
	./hog

hog_report.txt: gmon.out
	gprof hog > hog_report.txt

display: hog_report.txt
	xterm -e less hog_report.txt

.DUMMY: display

