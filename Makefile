all: TextWriter 

test: test.o RandWriter.o
	g++ test.o RandWriter.o -o test -l boost_unit_test_framework

TextWriter: RandWriter.o TextWriter.o
	g++ RandWriter.o TextWriter.o -o TextWriter

test.o: test.cpp
	g++ -c test.cpp -Wall -Werror -pedantic

RandWriter.o: RandWriter.h RandWriter.cpp
	g++ -c RandWriter.cpp -Wall -Werror -pedantic

TextWriter.o:
	g++ -c TextWriter.cpp -Wall -Werror -pedantic
clean: 
	rm *.o TextWriter test
