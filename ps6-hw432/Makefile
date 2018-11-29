# Author: Hao Wu
# Date: Nov 27, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++1z
OBJ = main.o game.o blockchain.o SPtr.o Serial.o tools.o
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
main.o: main.cpp SPtr.hpp Serial.hpp tools.hpp game.hpp block.hpp blockchain.hpp
game.o: game.cpp game.hpp tools.hpp blockchain.hpp
blockchain.o: blockchain.cpp blockchain.hpp block.hpp SPtr.hpp
main.o: main.cpp SPtr.hpp Serial.hpp
Serial.o: Serial.cpp Serial.hpp
SPtr.o: SPtr.cpp SPtr.hpp Serial.hpp block.hpp
tools.o: tools.cpp tools.hpp
