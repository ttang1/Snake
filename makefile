main: main.o Game.o
	g++ -std=c++11 -o main main.o Game.o -framework sfml-graphics -framework sfml-audio -framework sfml-window -framework sfml-system -framework SFML

main.o: main.cpp Game.hpp
	g++ -std=c++11 main.cpp -c 

Game.o: Game.hpp
	g++ -std=c++11 Game.cpp -c

clean:
	rm main.o 
	rm Game.o
	rm main
