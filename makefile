flags = -o passwords --std=c++11

passwords: generator.cpp help.cpp longform.cpp
	g++ generator.cpp $(flags) -o short --std=c++11
	g++ help.cpp -o help
	g++ longform.cpp -o long
	g++ random.cpp -o rand
	echo "hello" | sudo -S cp pw /usr/bin
	echo "done"
