/*
 * Rafael Basso
 * Tiago Gambim
 */
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Payment)
{
  RUN_TEST_CASE(Payment, TestPaymentUnderValue);
  RUN_TEST_CASE(Payment, TestPaymentOverValue);
  RUN_TEST_CASE(Payment, TestPaymentCorrectValue);
  RUN_TEST_CASE(Payment, TestPaymentZeroValue);
  RUN_TEST_CASE(Payment, TestPaymentNegativeValue);
  RUN_TEST_CASE(Payment, TestPaymentCorrectValue2);
  RUN_TEST_CASE(Payment, TestPaymentCorrectValue3);
  RUN_TEST_CASE(Payment, TestPaymentCorrectValue4);
  RUN_TEST_CASE(Payment, TestPaymentInvalidStatus);
  RUN_TEST_CASE(Payment, TestPaymentEmptyStatus);
}
