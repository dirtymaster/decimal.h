CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. --coverage -ls21_decimal
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

TEST_COMPILE = $(CC+FLAGS) s21_decimal.a tests.c $(CHECK_FLAGS) -L. -ls21_decimal

all: clean s21_decimal.a test

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM

rebuild: clean all

test: s21_decimal.a
	$(TEST_COMPILE)
	./a.out

gcov_report: test
	rm -f *.g*
	$(CC+FLAGS) s21*.c tests.c s21_decimal.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info

s21_decimal.a: s21_decimal.o
	ar rcs libs21_decimal.a *.o
	rm -rf *.o
	ranlib libs21_decimal.a
	cp libs21_decimal.a s21_decimal.a
	cp libs21_decimal.a ls21_decimal.a

s21_decimal.o:
	$(CC+FLAGS) -c s21*.c

lo:
	for i in `seq 100 $(OP)`;	do ./a.out; done;

check:
	cppcheck *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./a.out
else
	valgrind ./a.out --leak-check=full
endif
	make clean
