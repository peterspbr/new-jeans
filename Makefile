CXX = g++
CXXFLAGS = -Wall -O2
TARGET = target/newJeans
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
LIBS = -lgmp -lgmpxx

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

