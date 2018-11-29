# Author: Hao Wu
# Date: Nov 27, 2018

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++1z
OBJ = main.o driver.o blockchain.o block.o SPtr.o Serial.o tools.o
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
main.o: main.cpp SPtr.hpp Serial.hpp tools.hpp driver.hpp block.hpp blockchain.hpp
driver.o: driver.cpp driver.hpp tools.hpp blockchain.hpp
blockchain.o: blockchain.cpp blockchain.hpp block.hpp SPtr.hpp
block.o: block.cpp block.hpp SPtr.hpp
main.o: main.cpp SPtr.hpp Serial.hpp
Serial.o: Serial.cpp Serial.hpp
SPtr.o: SPtr.cpp SPtr.hpp Serial.hpp block.hpp
tools.o: tools.cpp tools.hpp
