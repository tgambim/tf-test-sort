/*
 * Rafael Basso
 * Tiago Gambim
 */

#include "../src/sort.h"
#include "unity.h"
#include "unity_fixture.h"

#define ARRAY_SIZE 100
#define ARRAY_START 20

#define EVEN_SIZE 6
#define ODD_SIZE 7

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

static void expect(const int * e, int size){
	startArray(fullExpected);
	memcpy(expected, e, size*sizeof(int));
	//verifica se ordenou e se nao editou as posicoes fora do limite
	TEST_ASSERT_EQUAL_INT_ARRAY(fullExpected, fullV, ARRAY_SIZE);
}

TEST_GROUP(Sort);


TEST_SETUP(Sort){
	v = fullV+ARRAY_START;
	expected = fullExpected+ARRAY_START;
}

TEST_TEAR_DOWN(Sort){
}

/* TESTA COM ARRAY JÁ ORDENADO */
/* tamanho ímpar */
static void withOrderedArrayOddSize(){
	with((int[]) {0, 2, 3, 4, 4, 4, INT_MAX}, ODD_SIZE);
}
static void expectOrderedArrayOddSize(){
	expect((int[]) {0, 2, 3, 4, 4, 4, INT_MAX}, ODD_SIZE);
}
void testOrderedArrayOddSize(void (*f)(int*, int)){
	withOrderedArrayOddSize();
	f(v, ODD_SIZE);
	expectOrderedArrayOddSize();
}
TEST(Sort, TestSelectionOrderedArrayOddSize){
	testOrderedArrayOddSize(selection_sort);
}
TEST(Sort, TestInsertionOrderedArrayOddSize){
	testOrderedArrayOddSize(insertion_sort);
}
TEST(Sort, TestShellOrderedArrayOddSize){
	testOrderedArrayOddSize(shell_sort);
}
TEST(Sort, TestQuickOrderedArrayOddSize){
	withOrderedArrayOddSize();
	quick_sort(v, 0, ODD_SIZE-1);
	expectOrderedArrayOddSize();
}
TEST(Sort, TestHeapOrderedArrayOddSize){
	testOrderedArrayOddSize(heap_sort);
}
TEST(Sort, TestMergeOrderedArrayOddSize){
	testOrderedArrayOddSize(merge_sort);
}
/* tamanho par */
static void withOrderedArrayEvenSize(){
	with((int[]) {0, 2, 3, 3, 3, INT_MAX}, EVEN_SIZE);
}
static void expectOrderedArrayEvenSize(){
	expect((int[]) {0, 2, 3, 3, 3, INT_MAX}, EVEN_SIZE);
}
void testOrderedArrayEvenSize(void (*f)(int*, int)){
	withOrderedArrayEvenSize();
	f(v, EVEN_SIZE);
	expectOrderedArrayEvenSize();
}
TEST(Sort, TestSelectionOrderedArrayEvenSize){
	testOrderedArrayEvenSize(selection_sort);
}
TEST(Sort, TestInsertionOrderedArrayEvenSize){
	testOrderedArrayEvenSize(insertion_sort);
}
TEST(Sort, TestShellOrderedArrayEvenSize){
	testOrderedArrayEvenSize(shell_sort);
}
TEST(Sort, TestQuickOrderedArrayEvenSize){
	withOrderedArrayEvenSize();
	quick_sort(v, 0, EVEN_SIZE-1);
	expectOrderedArrayEvenSize();
}
TEST(Sort, TestHeapOrderedArrayEvenSize){
	testOrderedArrayEvenSize(heap_sort);
}
TEST(Sort, TestMergeOrderedArrayEvenSize){
	testOrderedArrayEvenSize(merge_sort);
}
/* FIM DOS TESTES COM ARRAY JÁ ORDENADO */


/* TESTA COM ARRAY NÃO ORDENADO */
/* tamanho ímpar */
static void withMessyArrayOddSize(){
	with((int[]) {INT_MAX, 1, 2, 2, INT_MIN, 2, 2}, ODD_SIZE);
}
static void expectMessyArrayOddSize(){
	expect((int[]) {INT_MIN, 1, 2, 2, 2, 2, INT_MAX}, ODD_SIZE);
}
void testMessyArrayOddSize(void (*f)(int*, int)){
	withMessyArrayOddSize();
	f(v, ODD_SIZE);
	expectMessyArrayOddSize();
}
TEST(Sort, TestSelectionMessyArrayOddSize){
	testMessyArrayOddSize(selection_sort);
}
TEST(Sort, TestInsertionMessyArrayOddSize){
	testMessyArrayOddSize(insertion_sort);
}
TEST(Sort, TestShellMessyArrayOddSize){
	testMessyArrayOddSize(shell_sort);
}
TEST(Sort, TestQuickMessyArrayOddSize){
	withMessyArrayOddSize();
	quick_sort(v, 0, ODD_SIZE-1);
	expectMessyArrayOddSize();
}
TEST(Sort, TestHeapMessyArrayOddSize){
	testMessyArrayOddSize(heap_sort);
}
TEST(Sort, TestMergeMessyArrayOddSize){
	testMessyArrayOddSize(merge_sort);
}
/* tamanho par */
static void withMessyArrayEvenSize(){
	with((int[]) {INT_MAX, 2, 2, 2, INT_MIN, 0}, EVEN_SIZE);
}
static void expectMessyArrayEvenSize(){
	expect((int[]) {INT_MIN, 0, 2, 2, 2, INT_MAX}, EVEN_SIZE);
}
void testMessyArrayEvenSize(void (*f)(int*, int)){
	withMessyArrayEvenSize();
	f(v, EVEN_SIZE);
	expectMessyArrayEvenSize();
}
TEST(Sort, TestSelectionMessyArrayEvenSize){
	testMessyArrayEvenSize(selection_sort);
}
TEST(Sort, TestInsertionMessyArrayEvenSize){
	testMessyArrayEvenSize(insertion_sort);
}
TEST(Sort, TestShellMessyArrayEvenSize){
	testMessyArrayEvenSize(shell_sort);
}
TEST(Sort, TestQuickMessyArrayEvenSize){
	withMessyArrayEvenSize();
	quick_sort(v, 0, EVEN_SIZE-1);
	expectMessyArrayEvenSize();
}
TEST(Sort, TestHeapMessyArrayEvenSize){
	testMessyArrayEvenSize(heap_sort);
}
TEST(Sort, TestMergeMessyArrayEvenSize){
	testMessyArrayEvenSize(merge_sort);
}
//* FIM DOS TESTES COM ARRAY JÁ ORDENADO */


TEST(Sort, TestQuickOrderedArrayWrongParameters){
	with((int[]) {2, 1, 3, 1, 1, 3}, EVEN_SIZE);
	quick_sort(v, 0, EVEN_SIZE-1);
	expect((int[]) {1, 1, 1, 2, 3, 3}, EVEN_SIZE);
}
