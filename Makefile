build:
	g++ *.cpp -o game \
		-lglfw -lrt -lXrandr -lXinerama -lXi -lXcursor \
		-lGL -lm -ldl -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 \
		-lxcb-dri3 -lxcb-present -lxcb-sync -lxshmfence -lXxf86vm\
		-lXfixes -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp \
		-lstdc++ \
		-std=c++11 \
		-D_GNU_SOURCE=1 -D_REENTRANT

run: build
	./game
