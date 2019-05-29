FLAGS=-std=c++14 -fpermissive -fmessage-length=50 -w -g
DEPS=include/site.hpp include/json.hpp

pw-gen: main.cpp $(DEPS) utilities.cpp algorithms.cpp
	g++ main.cpp -o pw-gen $(FLAGS)
