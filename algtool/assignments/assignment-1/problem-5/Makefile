COMPILE = g++ -pipe -O2 -std=c++11 


all: fibonacci_huge.cpp
	$(COMPILE) -DFIMA_LOCAL fibonacci_huge.cpp -o fibonacci_huge 

submission:
	$(COMPILE) fibonacci_huge.cpp -o fibonacci_huge 

clean:
	rm -f fibonacci_huge
