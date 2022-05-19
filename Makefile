
shopping_cart: main.o
	g++ main.o -o shopping_cart

main.o: main.cpp datamodel.h
	g++ -c main.cpp

clean:
	rm *.o shopping_cart