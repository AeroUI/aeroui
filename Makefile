#######################################################
#	###################AERO UI######################  #

CFLAGS := -std=c++11 -Iinclude -DAIDEBUG
LDFLAGS := -framework OpenGL
LIBS := `pkg-config --cflags --libs --static glfw3` `pkg-config --libs --cflags glew glm`

all: build

build:
	g++ $(CFLAGS) $(LIBS) src/main.cpp $(LDFLAGS)

clean:
	rm a.out

.PHONY: build