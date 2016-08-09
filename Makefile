LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: pong

target/game.o: src/game.cpp
	$(CXX) -Wall -c src/game.cpp -o target/game.o $(LIBS)

target/main.o: src/main.cpp target/game.o
	$(CXX) -Wall -c src/main.cpp -o target/main.o $(LIBS)

pong: target/main.o
	@echo "BUILDING"
	$(CXX) -Wall -o pong target/*.o $(LIBS)


clean:
	-rm -f target/* pong



