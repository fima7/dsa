COMPILE = g++ -pipe -O2 -std=c++11 


all: different_summands.cpp
	$(COMPILE) -DFIMA_LOCAL different_summands.cpp -o different_summands 

submission:
	$(COMPILE) different_summands.cpp -o different_summands 

clean:
	rm -f different_summands
