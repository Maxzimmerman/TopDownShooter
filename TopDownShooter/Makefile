# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra `pkg-config --cflags raylib`
LDFLAGS = `pkg-config --libs raylib`

# Sources
SRCS = main.cpp player.cpp game.cpp bullet.cpp camera.cpp enemy.cpp button.cpp Weapon.cpp Level.cpp XP.cpp MineField.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = game

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
