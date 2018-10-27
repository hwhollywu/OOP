# Author: Hao Wu
# Date: October 26, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++1z
OBJ = simulator.o main.o agent.o tools.o
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
agent.o: agent.cpp agent.hpp tools.hpp
tools.o: tools.cpp tools.hpp
