CC = g++
FLAGS = -Wall -Werror -Wextra
STLIB = matrix.a

all: clean build matrix.a test clean

build: matrix.cpp
	@$(CC) -c $(FLAGS) -std=c++17 matrix.cpp -o matrix.o

matrix.a: build
	@ar rcs $(STLIB) *.o

test: $(STLIB)
	@$(CC) $(FLAGS) -lgtest -std=c++17 $(STLIB) test/*.cpp -o unit_test
	@./unit_test

clean:
	rm -rf *.o *.a
	rm -rf unit_test

check:
	@cp ../materials/linters/.clang-format ./
	clang-format -n *.cpp test/*.cpp *.h 
	@rm -rf .clang-format

.PHONY: all build matrix.a test check