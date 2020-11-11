/*
 * Rafael Basso
 * Tiago Gambim
 */
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
	/* TESTA COM ARRAY JÁ ORDENADO */
	/* tamanho ímpar */
  RUN_TEST_CASE(Sort, TestSelectionOrderedArrayOddSize);
  RUN_TEST_CASE(Sort, TestInsertionOrderedArrayOddSize);
  RUN_TEST_CASE(Sort, TestShellOrderedArrayOddSize);
  RUN_TEST_CASE(Sort, TestQuickOrderedArrayOddSize);
  RUN_TEST_CASE(Sort, TestHeapOrderedArrayOddSize);
  RUN_TEST_CASE(Sort, TestMergeOrderedArrayOddSize); 
	/* tamanho par */
  RUN_TEST_CASE(Sort, TestSelectionOrderedArrayEvenSize);
  RUN_TEST_CASE(Sort, TestInsertionOrderedArrayEvenSize);
  RUN_TEST_CASE(Sort, TestShellOrderedArrayEvenSize);
  RUN_TEST_CASE(Sort, TestQuickOrderedArrayEvenSize);
  RUN_TEST_CASE(Sort, TestHeapOrderedArrayEvenSize);
  RUN_TEST_CASE(Sort, TestMergeOrderedArrayEvenSize); 
  
	/* TESTA COM ARRAY NÃO ORDENADO */
	/* tamanho ímpar */
  RUN_TEST_CASE(Sort, TestSelectionMessyArrayOddSize);
  RUN_TEST_CASE(Sort, TestInsertionMessyArrayOddSize);
  RUN_TEST_CASE(Sort, TestShellMessyArrayOddSize);
  RUN_TEST_CASE(Sort, TestQuickMessyArrayOddSize);
  RUN_TEST_CASE(Sort, TestHeapMessyArrayOddSize);
  RUN_TEST_CASE(Sort, TestMergeMessyArrayOddSize); 
	/* tamanho par */
  RUN_TEST_CASE(Sort, TestSelectionMessyArrayEvenSize);
  RUN_TEST_CASE(Sort, TestInsertionMessyArrayEvenSize);
  RUN_TEST_CASE(Sort, TestShellMessyArrayEvenSize);
  RUN_TEST_CASE(Sort, TestQuickMessyArrayEvenSize);
  RUN_TEST_CASE(Sort, TestHeapMessyArrayEvenSize);
  RUN_TEST_CASE(Sort, TestMergeMessyArrayEvenSize); 
  
  
  RUN_TEST_CASE(Sort, TestQuickOrderedArrayWrongParameters); 
  
}
