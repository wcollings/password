$(eval PREV_USR=`who -a | gawk 'FNR == 2 { print $$$$1;}'`)

install:
	cp src/algorithms.cpp src/algos
	cp src/main.cpp src/main
	cp src/utilities.cpp src/util
	sed -i -e 's/settings.json/\/usr\/local\/etc\/pw-gen\/settings.json/g' src/utilities.cpp
	@[ -e src/include/json.hpp ] || wget -NO src/include/json.hpp https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp
	@[ -e db.json ] || echo "{}" >>db.json
	g++ src/main.cpp -o pw-gen -std=c++11 -fpermissive -fmessage-length=50 -w -O3
	cp src/pw-gen /usr/local/bin
	@[ -d /usr/local/etc/pw-gen ] || mkdir /usr/local/etc/pw-gen
	@[ -d /home/$(PREV_USR)/.pw-gen ] || mkdir /home/$(PREV_USR)/.pw-gen
	sed -i -e "s/db_temp/\/home\/$(PREV_USR)\/.pw-gen\/db.json/g" settings.json
	mv src/util src/utilities.cpp
	mv src/algos src/algorithms.cpp
	mv src/main src/main.cpp
	cp settings.json /usr/local/etc/pw-gen
	cp db.json /home/$(PREV_USR)/.pw-gen
	cp words.txt /usr/local/etc/pw-gen
	touch /var/log/pw-gen.log
	chmod 7 /var/log/pw-gen.log
	gzip -k pw-gen.1
	cp pw-gen.1.gz /usr/local/share/man/man1
	mandb

update:
	cp src/utilities.cpp src/util.cpp
	cp src/main.cpp src/m.cpp
	sed -i -e 's@settings.json@\/usr\/local\/etc\/pw-gen\/settings.json@g' src/util.cpp
	sed -i -e 's@utilities.cpp@util.cpp@g' src/m.cpp
	g++ src/m.cpp -o pw-gen -std=c++11 -fpermissive -fmessage-length=50 -w -O3
	cp src/pw-gen /usr/local/bin
	touch /var/log/pw-gen.log
	chmod 7 /var/log/pw-gen.log
	gzip -k pw-gen.1
	cp pw-gen.1.gz /usr/local/share/man/man1
	mandb
