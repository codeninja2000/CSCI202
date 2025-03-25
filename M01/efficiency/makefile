CCX=g++
CXXFLAGS=-std=c++17
OBJ = main.o

ifeq ($(OS),Windows_NT)
    UNAME_S := Windows
else
    UNAME_S := $(shell uname -s)
endif

ifeq ($(UNAME_S), Windows)
    TARGET = main.exe
endif
ifeq ($(UNAME_S), Linux)
    TARGET = main
endif
ifeq ($(UNAME_S), Darwin)
    TARGET = main
endif

%.o: %.cpp $(DEPS)
	$(CCX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)