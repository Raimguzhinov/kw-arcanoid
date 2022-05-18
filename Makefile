bin/sfml : src/Main.cpp src/Platform.cpp src/Ball.cpp
	 clang++ -std=c++11 src/Main.cpp -I include -o bin/sfml -L lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	
run :
	./bin/sfml

