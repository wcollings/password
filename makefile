all:
	sed -i -e 's/settings.json/\/usr\/local\/etc\/pw-gen\/settings.json/g' src/utilities.cpp
	@[ -e src/include/json.hpp ] || wget -NO src/include/json.hpp https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp
	@[ -e db.json ] || echo "{}" >>db.json
	g++ src/main.cpp -o pw-gen -std=c++11 -fpermissive -fmessage-length=50 -w

install:
	$(eval PREV_USR=`who -a | gawk 'FNR > 1 { print $$$$1;}'`)
	cp pw-gen /usr/local/bin
	@[ -d /usr/local/etc/pw-gen ] || mkdir /usr/local/etc/pw-gen
	@[ -d /home/$(PREV_USR)/.pw-gen ] || mkdir /home/$(PREV_USR)/.pw-gen
	sed -i -e "s/db_temp/\/home\/$(PREV_USR)\/.pw-gen\/db.json/g" settings.json
	cp settings.json /usr/local/etc/pw-gen
	cp db.json /home/$(PREV_USR)/.pw-gen
	cp words.txt /usr/local/etc/pw-gen
