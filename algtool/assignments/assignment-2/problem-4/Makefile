COMPILE = g++ -pipe -O2 -std=c++11 


all: covering_segments.cpp
	$(COMPILE) -DFIMA_LOCAL covering_segments.cpp -o covering_segments 

submission:
	$(COMPILE) covering_segments.cpp -o covering_segments 

clean:
	rm -f covering_segments
