/*
 * Rafael Basso
 * Tiago Gambim
 */

#include "../payment.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Payment);

TEST_SETUP(Payment){
}

TEST_TEAR_DOWN(Payment){
}

TEST(Payment, TestPaymentUnderValue){
	int result;
	char status[20] = "regular";
	result = payment(0.009, status);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Payment, TestPaymentOverValue){
	int result;
	char status[20] = "regular";
	result = payment(99999.01, status);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Payment, TestPaymentCorrectValue){
	int result;
	char status[20] = "regular";
	result = payment(50.43, status);
	TEST_ASSERT_EQUAL_INT(0, result);
}

TEST(Payment, TestPaymentZeroValue){
	int result;
	char status[20] = "regular";
	result = payment(0, status);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Payment, TestPaymentNegativeValue){
	int result;
	char status[20] = "regular";
	result = payment(-3, status);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Payment, TestPaymentCorrectValue2){
	int result;
	char status[20] = "estudante";
	result = payment(500.37, status);
	TEST_ASSERT_EQUAL_INT(0, result);
}

TEST(Payment, TestPaymentCorrectValue3){
	int result;
	char status[20] = "aposentado";
	result = payment(500.37, status);
	TEST_ASSERT_EQUAL_INT(0, result);
}

TEST(Payment, TestPaymentCorrectValue4){
	int result;
	char status[20] = "VIP";
	result = payment(50000.0, status);
	TEST_ASSERT_EQUAL_INT(0, result);
}

TEST(Payment, TestPaymentInvalidStatus){
	int result;
	char status[20] = "blablablalba";
	result = payment(1000.0, status);
	TEST_ASSERT_EQUAL_INT(2, result);
}

TEST(Payment, TestPaymentEmptyStatus){
	int result;
	char status[20] = "";
	result = payment(97532.18, status);
	TEST_ASSERT_EQUAL_INT(2, result);
}


