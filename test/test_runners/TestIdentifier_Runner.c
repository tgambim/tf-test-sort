/*
 * Rafael Basso
 * Tiago Gambim
 */
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Identifier)
{
  RUN_TEST_CASE(Identifier, TestEmptyString);
  RUN_TEST_CASE(Identifier, TestValidString1);
  RUN_TEST_CASE(Identifier, TestStartUppercase);
  RUN_TEST_CASE(Identifier, TestValidString6);
  RUN_TEST_CASE(Identifier, TestInvalidString7);
  RUN_TEST_CASE(Identifier, TestSpecialChar);
  RUN_TEST_CASE(Identifier, TestSpecialChar2);
  RUN_TEST_CASE(Identifier, TestSpecialChar3);
  RUN_TEST_CASE(Identifier, TestSpecialCharMiddle);
  RUN_TEST_CASE(Identifier, TestStartNumber);
}
