CXX = g++
CXXFLAGS = -Wall -O2
TARGET = target/newJeans
TARGETDIR = target
SRC = $(wildcard src/*.cpp)
OBJDIR = obj
OBJ = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRC))
LIBS = -lgmp -lgmpxx

all: $(TARGET)

$(TARGET): $(OBJ) | $(TARGETDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(OBJDIR) $(TARGETDIR)

.PHONY: all clean

