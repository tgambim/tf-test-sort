/*
 * Rafael Basso
 * Tiago Gambim
 */
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
	/* TESTA COM ARRAY JÁ ORDENADO */
  RUN_TEST_CASE(Sort, TestSelectionOrderedArray);
  RUN_TEST_CASE(Sort, TestInsertionOrderedArray);
  RUN_TEST_CASE(Sort, TestShellOrderedArray);
  RUN_TEST_CASE(Sort, TestQuickOrderedArray);
  RUN_TEST_CASE(Sort, TestHeapOrderedArray);
  RUN_TEST_CASE(Sort, TestMergeOrderedArray); 
	/* TESTA COM ARRAY NÃO ORDENADO */
  RUN_TEST_CASE(Sort, TestSelectionMessyArray);
  RUN_TEST_CASE(Sort, TestInsertionMessyArray);
  RUN_TEST_CASE(Sort, TestShellMessyArray);
  RUN_TEST_CASE(Sort, TestQuickMessyArray);
  RUN_TEST_CASE(Sort, TestHeapMessyArray);
  RUN_TEST_CASE(Sort, TestMergeMessyArray); 
}
