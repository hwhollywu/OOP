# Author: Hao Wu
# Date: Dec 7, 2018.

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o simulator.o population.o blockchain.o block.o SPtr.o Serial.o tools.o
TARGET = blockchain
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
main.o: main.cpp SPtr.hpp Serial.hpp tools.hpp simulator.hpp population.hpp 
simulator.o: simulator.cpp simulator.hpp population.hpp tools.hpp fickle.hpp crowd.hpp nakamoto.hpp agentbase.hpp agent.hpp blockchain.hpp block.hpp 
population.o: population.cpp population.hpp tools.hpp fickle.hpp crowd.hpp nakamoto.hpp agentbase.hpp agent.hpp blockchain.hpp block.hpp 
blockchain.o: blockchain.cpp blockchain.hpp block.hpp SPtr.hpp
block.o: block.cpp block.hpp SPtr.hpp
SPtr.o: SPtr.cpp SPtr.hpp Serial.hpp block.hpp
Serial.o: Serial.cpp Serial.hpp
tools.o: tools.cpp tools.hpp
