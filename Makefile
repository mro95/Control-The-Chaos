build:
	g++ *.cpp -o game \
		-lglfw -lGL -lstdc++ \
		-std=c++11 \
		-D_GNU_SOURCE=1 -D_REENTRANT

run: build
	./game
