INCLUDES=-Idependencies/sfml/include -Iinclude
STATIC_LIB=-L./dependencies/sfml/lib
LIBS=-lsfml-graphics -lsfml-window -lsfml-system


all: pong

target/game.o: src/game.cpp
	$(CXX) -Wall -c src/game.cpp -o target/game.o $(INCLUDES)

target/main.o: src/main.cpp target/game.o
	$(CXX) -Wall -c src/main.cpp -o target/main.o $(INCLUDES)

pong: target/main.o
	@echo "BUILDING"
	$(CXX) -Wall -o pong target/*.o $(STATIC_LIB) $(LIBS)


clean:
	-rm target/* pong



