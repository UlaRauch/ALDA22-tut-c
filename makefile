# if you want to dive into makefiles have a look at:
#	https://makefiletutorial.com/
#	http://www.gnu.org/software/make/manual/make.html

CXX=g++
CPPFLAGS=--std=c++17

DEPS=main.hpp
OBJ=main.o tests/tests.o

all: clean test

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

exercise1: $(OBJ)
	$(CXX) -o $@ $^ $(CPPFLAGS)

test: exercise1
	# executes all tests
	./exercise1

clean:
	rm -f exercise1
