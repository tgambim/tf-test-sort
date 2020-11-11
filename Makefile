# Travis example for Identifier created by Rafael Garibotti
GCCFLAGS = -g -Wall -Wfatal-errors
ALL = identifier
GCC = gcc
UNITY_ROOT=Unity

TARGET1 = all_tests
SRC_TEST=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/sort.c \
  test/TestSort.c \
  test/test_runners/TestSort_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src

SRC_FILES=\
  src/array.c \
  src/get_opt.c \
  src/sort.c \
  src/main.c 


all: $(ALL)

app: clean
	$(GCC) $(GCCFLAGS) -o app $(SRC_FILES)

cov: test
	gcov -b sort.c

clean:
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov $(TARGET1) app *.out.*

test: clean
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage $(INC_DIRS) $(SRC_TEST) -o $(TARGET1)
	- ./$(TARGET1) -v

cppcheck: clean
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC_FILES)

valgrind: clean app
	valgrind --leak-check=full --show-leak-kinds=all ./app -a $(method) -n 6 -s descending -P
	valgrind --tool=cachegrind ./app -a $(method) -n 6 -s descending -P
	valgrind --tool=callgrind ./app -a $(method) -n 6 -s descending -P
	valgrind --tool=massif ./app -a $(method) -n 6 -s descending -P

sanitizer: clean
	$(GCC) $(GCCFLAGS) -fsanitize=address -o app $(SRC_FILES)
	./app -a $(method) -n 6 -s descending -P
	#$(GCC) $(GCCFLAGS) -fsanitize=memory -o app $(SRC_FILES)
	#./app -a $(method) -n 6 -s descending -P

testall: test cppcheck sanitizer valgrind