COMPILE = g++ -pipe -O2 -std=c++11 


all: fractional_knapsack.cpp
	$(COMPILE) -DFIMA_LOCAL fractional_knapsack.cpp -o fractional_knapsack 

submission:
	$(COMPILE) fractional_knapsack.cpp -o fractional_knapsack 

clean:
	rm -f fractional_knapsack
