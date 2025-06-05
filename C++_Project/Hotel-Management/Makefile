# Compiler & Flags
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -IInc

# Folders
SRCDIR = Src
OBJDIR = Bin
INCDIR = Inc

# Files .cpp
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Create a set of corresponding object files
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Executable file
TARGET = $(OBJDIR)/hotel_management

# Default rule (build all)
all: $(TARGET)

# Link
$(TARGET): $(OBJECTS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiler .cpp -> .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean - delete all files .o and executable file
clean: 
	rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean
