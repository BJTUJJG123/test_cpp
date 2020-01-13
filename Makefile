all:
	g++ -std=c++11 -pthread str_test.cpp test.cpp -o test

clean:
	rm -rf test
