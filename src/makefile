FLAGS=-std=c++11 -fpermissive -fmessage-length=50 -w -g
DEPS=include/site.hpp include/json.hpp

pw-gen: main.cpp $(DEPS) util.o  algo.o
	g++ main.cpp -o pw-gen $(FLAGS)

util.o: utilities.cpp
	g++ utilities.cpp $(FLAGS) -c -o util.o

algo.o: algorithms.cpp
	g++ algorithms.cpp -c $(FLAGS) -o algo.o
	
