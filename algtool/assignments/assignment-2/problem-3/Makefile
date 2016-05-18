COMPILE = g++ -pipe -O2 -std=c++11 


all: dot_product.cpp
	$(COMPILE) -DFIMA_LOCAL dot_product.cpp -o dot_product 

submission:
	$(COMPILE) dot_product.cpp -o dot_product 

clean:
	rm -f dot_product
