INCLUDE_DIR=./dependencies/sfml/include
LIB_DIR=./dependencies/sfml/lib
LIBS=-lsfml-graphics -lsfml-window -lsfml-system


all: target/pong

run: target/pong
	./target/pong

target/obj/%.o: src/%.cpp
	mkdir -p ./target/obj
	$(CXX) -c $< -o $@ -I $(INCLUDE_DIR)

target/obj/%.o: src/%.hpp
	mkdir -p ./target/obj
	$(CXX) -c $< -o $@ -I $(INCLUDE_DIR)

target/pong: target/obj/main.o
	@echo "BUILDING"
	$(CXX) -o target/pong target/obj/*.o -L $(LIB_DIR) $(LIBS)

clean:
	rm -r target/.



