
#CXX = g++
CXX = clang++

SOURCE_CXX = $(foo).cpp
TARGET = $(foo)
LDFLAGS_COMMON = -std=c++2a  -lboost_program_options
all:
	$(CXX) $(SOURCE_CXX) $(OBJECTS_C) $(LDFLAGS_COMMON) -o $(TARGET)
clean:
	rm -rf *.o $(TARGET)

