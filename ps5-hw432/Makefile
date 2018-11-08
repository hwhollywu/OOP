# Author: Hao Wu
# Date: Nov 3, 2018.
#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = simulator.o population.o main.o tools.o
TARGET = consensus2
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
simulator.o: simulator.cpp simulator.hpp population.hpp tools.hpp fickle.hpp crowd.hpp agent.hpp
population.o: population.cpp population.hpp tools.hpp fickle.hpp crowd.hpp agent.hpp
main.o: main.cpp tools.hpp simulator.hpp agent.hpp
tools.o: tools.cpp tools.hpp
