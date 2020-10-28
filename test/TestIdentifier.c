/*
 * Rafael Basso
 * Tiago Gambim
 */

#include "../identifier.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Identifier);

TEST_SETUP(Identifier){
}

TEST_TEAR_DOWN(Identifier){
}

TEST(Identifier, TestEmptyString){
	char * str = "";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Identifier, TestValidString1){
	char * str = "a";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(0, result);
}

TEST(Identifier, TestStartUppercase){
	char * str = "AA";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(0, result);
}

TEST(Identifier, TestValidString6){
	char * str = "abc123";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(0, result);
}

TEST(Identifier, TestInvalidString7){
	char * str = "abc1234";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Identifier, TestSpecialChar){
	char * str = "@";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Identifier, TestSpecialChar2){
	char * str = "{";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Identifier, TestSpecialChar3){
	char * str = "A{";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Identifier, TestSpecialCharMiddle){
	char * str = "ab#c";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(1, result);
}

TEST(Identifier, TestStartNumber){
	char * str = "1a2b";
	int result = identifier(str);
	TEST_ASSERT_EQUAL_INT(1, result);
}



