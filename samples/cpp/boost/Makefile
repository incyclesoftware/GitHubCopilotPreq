CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lboost_system -lboost_filesystem -lboost_thread -lpthread

TARGET = bin/boost_sample
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: clean $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin