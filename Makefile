PROG = SDL2_Pong

SDL_ROOT = /usr/local/include/SDL2

SDL_LIBS = -lSDL2 -lSDL2_mixer

CPPFLAGS = -I$(SDL_ROOT) -std=c++0x
LDFLAGS = $(SDL_LIBS)

PROG_SRCS = main.cpp game.cpp sprite.cpp
PROG_OBJS = $(PROG_SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(PROG_OBJS)
	$(LINK.cc) $^ -o $@