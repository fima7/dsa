COMPILE = g++ -pipe -O2 -std=c++11 


all: change.cpp
	$(COMPILE) -DFIMA_LOCAL change.cpp -o change 

submission:
	$(COMPILE) change.cpp -o change 

clean:
	rm -f change
