FLAGS=-std=c++11 -fpermissive -fmessage-length=50

.phony:

utility: bin/utilities.cpp 
	g++ bin/utilities.cpp -c $(FLAGS)

algorithm: bin/algorithms.cpp
	g++ bin/algorithms.cpp -c $(FLAGS)


all: initial utility algorithm bin/main.cpp
	g++ bin/main.cpp -o pw-gen $(FLAGS)


initial:
	@[ -f include/json.hpp ] || wget -NO include/json.hpp https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp
	@[ -f db.json ] || echo -e "{\n}" >> db.json

clean:
	rm *.o

push: clean
	rm pw-gen
	rm include/json.hpp

install:
	cp pw-gen /usr/local/bin


	