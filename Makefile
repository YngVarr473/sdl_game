compile: build run

build:
	g++ ./src/main.cpp -o ./out/sdl_game.exe -LSDL3

run: 
	./out/sdl_game.exe