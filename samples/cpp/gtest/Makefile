CXX = g++
CXXFLAGS = -std=c++17 -isystem /usr/include/gtest -pthread
LDFLAGS = -lgtest -lgtest_main -pthread

all: test_sample
test_sample: bin/test_sample.o
	$(CXX) $(CXXFLAGS) -o bin/test_sample bin/test_sample.o $(LDFLAGS)

bin/test_sample.o: test_sample.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -c test_sample.cpp -o bin/test_sample.o

clean:
	rm -rf ./bin

run: clean test_sample
	./bin/test_sample