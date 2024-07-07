CXX = g++
CXXFLAGS = -Wall -O2
TARGET = target/newJeans
SRC = $(wildcard src/*.cpp)
OBJDIR = obj
OBJ = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRC))
LIBS = -lgmp -lgmpxx

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(OBJDIR)

.PHONY: all clean

