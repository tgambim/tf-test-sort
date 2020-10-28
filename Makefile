# Travis example for Identifier created by Rafael Garibotti
GCCFLAGS = -g -Wall -Wfatal-errors
ALL = identifier
GCC = gcc
UNITY_ROOT=Unity

TARGET1 = all_tests
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  payment.c \
  test/TestPayment.c \
  test/test_runners/TestPayment_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src


all: $(ALL)

identifier: identifier.c clean
	$(GCC) $(GCCFLAGS) -o $@ $@.c

cov: identifier.c 
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o $@ identifier.c

clean:
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov $(TARGET1) *.out.*

test: clean
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage $(INC_DIRS) $(SRC_FILES1) -o $(TARGET1)
	- ./$(TARGET1) -v

cppcheck: clean
	cppcheck --enable=all --suppress=missingIncludeSystem identifier.c

valgrind: clean identifier
	valgrind --leak-check=full --show-leak-kinds=all ./identifier dsa
	valgrind --tool=cachegrind ./identifier dsa
	valgrind --tool=callgrind ./identifier dsa
	valgrind --tool=massif ./identifier dsa

sanitizer: clean
	$(GCC) $(GCCFLAGS) -fsanitize=address -o identifier identifier.c
	./identifier dsa

testall: test cppcheck sanitizer valgrind