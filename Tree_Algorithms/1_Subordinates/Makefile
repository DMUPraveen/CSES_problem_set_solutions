CC := g++
FLAGS := -O3


all: Solution


Solution: Solution.cpp
	$(CC) Solution.cpp -o Solution $(FLAGS)


run: Solution
	cat Sample.txt | ./Solution

clean:
	rm Solution
