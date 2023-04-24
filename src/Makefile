CC = g++
FLAGS = -Wall -Werror -Wextra
STLIB = s21_matrix_oop.a

all: clean build s21_matrix_oop.a test clean

build: s21_matrix_oop.cpp
	@$(CC) -c $(FLAGS) -std=c++17 s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_matrix_oop.a: build
	@ar rcs $(STLIB) s21_*.o

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

.PHONY: all build s21_matrix_oop.a test check