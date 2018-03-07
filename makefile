FLAGS=-std=c++11 -fpermissive -fmessage-length=50

all: utility algorithm main.cpp
	g++ main.cpp -o pw-gen $(FLAGS)

utility: utilities.cpp 
	g++ utilities.cpp -c $(FLAGS)

algorithm: algorithms.cpp
	g++ algorithms.cpp -c $(FLAGS)

install:
	cp pw-gen /usr/local/bin
	