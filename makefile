flags=-fpermissive -fmessage-length=50 -std=c++11

pw:main.o

main.o:main.cpp utilities.o
	g++ main.cpp $(flags) -o pw

utilities.o: utilities.cpp algorithms.cpp site.h
	g++ site.h
	g++ utilities.cpp $(flags) -c
	g++ algorithms.cpp $(flags) -c