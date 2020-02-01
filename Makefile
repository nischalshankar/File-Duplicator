# Compiler and Compiler Flags
CXX			= g++
CXXFLAGS	= -std=c++17 -O3
# Executable
EXEC 		= duplicator
# Source Files and Headers
SOURCES 	= main.cpp

# Recipes
$(EXEC): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)
clean:
	rm $(EXEC)
