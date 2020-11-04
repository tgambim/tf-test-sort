/*
 * Rafael Basso
 * Tiago Gambim
 */

#include "../src/sort.h"
#include "unity.h"
#include "unity_fixture.h"

#define ARRAY_SIZE 100
#define ARRAY_START 20


static int fullV[ARRAY_SIZE];
static int* v;
static int fullExpected[ARRAY_SIZE];
static int* expected;

/*
 * sempre inicializa um array maior e coloca os dados desejados no meio desse array
 * assim conseguimos comparar no final para ver se a função não operou fora dos limites de memória
 * 
 */

static void startArray(int *vet){
	memset(vet, 0, ARRAY_SIZE*sizeof(int));
}

static void debugArrays(){
	printf("\n");
	for(int i = 0; i<ARRAY_SIZE; i++)
		printf("actual: %d  - expected: %d\n", fullV[i], fullExpected[i]);
}

static void with(const int * data, int size){
	startArray(fullV);
	memcpy(v, data, size*sizeof(int));
}

static void withOrderedArray(){
	with((int[]) {0, 2, 3, 4, INT_MAX}, 5);
}

static void withMessyArray(){
	with((int[]) {INT_MAX, 2, INT_MIN, 1, 0}, 5);
}


static void expect(const int * e, int size){
	startArray(fullExpected);
	memcpy(expected, e, size*sizeof(int));
	//verifica se ordenou e se nao editou as posicoes fora do limite
	TEST_ASSERT_EQUAL_INT_ARRAY(fullExpected, fullV, ARRAY_SIZE);
}

static void expectOrderedArray(){
	expect((int[]) {0, 2, 3, 4, INT_MAX}, 5);
}

static void expectMessyArray(){
	expect((int[]) {INT_MIN, 0, 1, 2, INT_MAX}, 5);
}

TEST_GROUP(Sort);


TEST_SETUP(Sort){
	v = fullV+ARRAY_START;
	expected = fullExpected+ARRAY_START;
}

TEST_TEAR_DOWN(Sort){
}

/* TESTA COM ARRAY JÁ ORDENADO */
TEST(Sort, TestSelectionOrderedArray){
	testOrderedArray(selection_sort, 5);
}
TEST(Sort, TestInsertionOrderedArray){
	testOrderedArray(insertion_sort, 5);
}
TEST(Sort, TestShellOrderedArray){
	testOrderedArray(shell_sort, 5);
}
TEST(Sort, TestQuickOrderedArray){
	withOrderedArray();
	quick_sort(v, 0, 4);
	expectOrderedArray();
}
TEST(Sort, TestHeapOrderedArray){
	testOrderedArray(heap_sort, 5);
}
TEST(Sort, TestMergeOrderedArray){
	testOrderedArray(merge_sort, 5);
}

void testOrderedArray(void (*f)(int*, int), int size){
	withOrderedArray();
	f(v, size);
	expectOrderedArray();
}
/* FIM DOS TESTES COM ARRAY JÁ ORDENADO */

/* TESTA COM ARRAY NÃO ORDENADO */
TEST(Sort, TestSelectionMessyArray){
	testMessyArray(selection_sort, 5);
}
TEST(Sort, TestInsertionMessyArray){
	testMessyArray(insertion_sort, 5);
}
TEST(Sort, TestShellMessyArray){
	testMessyArray(shell_sort, 5);
}
TEST(Sort, TestQuickMessyArray){
	withMessyArray();
	quick_sort(v, 0, 4);
	expectMessyArray();
}
TEST(Sort, TestHeapMessyArray){
	testMessyArray(heap_sort, 5);
}
TEST(Sort, TestMergeMessyArray){
	testMessyArray(merge_sort, 5);
}
void testMessyArray(void (*f)(int*, int), int size){
	withMessyArray();
	f(v, size);
	expectMessyArray();
}
//* FIM DOS TESTES COM ARRAY JÁ ORDENADO */
