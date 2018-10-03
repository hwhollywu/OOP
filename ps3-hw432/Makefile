# Author: Hao Wu
# Date: September 30, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++1z
OBJ = game.o main.o thinkadot.o flipflop.o tools.o
TARGET = tad
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
game.o: game.cpp game.hpp tools.hpp flipflop.hpp thinkadot.hpp
main.o: main.cpp tools.hpp game.hpp flipflop.hpp thinkadot.hpp
thinkadot.o: thinkadot.cpp thinkadot.hpp tools.hpp flipflop.hpp
token.o: flipflop.cpp flipflop.hpp tools.hpp
tools.o: tools.cpp tools.hpp
