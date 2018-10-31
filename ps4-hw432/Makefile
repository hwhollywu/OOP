# Author: Hao Wu
# Date: October 26, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = simulator.o main.o tools.o
TARGET = consensus
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
simulator.o: simulator.cpp simulator.hpp tools.hpp agent.hpp
main.o: main.cpp tools.hpp simulator.hpp agent.hpp
tools.o: tools.cpp tools.hpp
