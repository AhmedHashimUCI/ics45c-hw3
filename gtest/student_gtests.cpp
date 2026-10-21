#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
	EXPECT_EQ(String::strlen("Ahmed"), 5);
}

TEST(StringFunction, strcpy) {
    char result[20];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");

	EXPECT_EQ(String::strcpy(result, "Lana Del Rey"), result);
	EXPECT_STREQ(result, "Lana Del Rey");

}

TEST(StringFunction, strncpy) {
    char result[20];

	EXPECT_EQ(String::strncpy(result, "Lana Del Rey", 4), result);
	EXPECT_STREQ(result, "Lana");

	EXPECT_EQ(String::strncpy(result, "Hello", 0), result);
	EXPECT_STREQ(result, "");
}

TEST(StringFunction, strcat) {
	char result[100] = "Lana";

	EXPECT_EQ(String::strcat(result, " Del Rey"), result);
	EXPECT_STREQ(result, "Lana Del Rey");

	char empty[100] = "";
	EXPECT_EQ(String::strcat(empty, "Lana the best"), empty);
	EXPECT_STREQ(empty, "Lana the best");

	char empty1[100] = "";

	EXPECT_EQ(String::strcat(empty1, " Space"), empty1);
	EXPECT_STREQ(empty1, " Space");

   	
}

TEST(StringFunction, strncat) {
    char result[100] = "Arctic";

	EXPECT_EQ(String::strncat(result, " MonkeyAAA", 7), result);
    EXPECT_STREQ(result, "Arctic Monkey");

	char result1[100] = "Arctic";

	EXPECT_EQ(String::strncat(result1, "MONKEY", 0), result1);
    EXPECT_STREQ(result1, "Arctic");
    
	char result2[100] = "Arctic";

	EXPECT_EQ(String::strncat(result2, "a", 1), result2);
    EXPECT_STREQ(result2, "Arctica");
}

TEST(StringFunction, strcmp) {
    
	EXPECT_EQ(String::strcmp("Arctic", "Arctic"), 0);
	EXPECT_EQ(String::strcmp("", ""), 0);

}

TEST(StringFunction, strncmp) {
   	EXPECT_EQ(String::strncmp("Arctic", "Arctic Monkeys", 6), 0);
	EXPECT_LT(String::strncmp("", " Lana", 1), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[100];
	String::reverse_cpy(result,"Lana");
	EXPECT_STREQ(result, "anaL");

	char empty[100];
	String::reverse_cpy(empty, "");
	EXPECT_STREQ(empty, "");


}

TEST(StringFunction, strchr) {
    
	const char * str = "Lana Del Rey";
	const char* result = String::strchr(str, 'D');

	EXPECT_STREQ(result, "Del Rey");

	
	const char * s = "Lana Del Rey";
	const char *second = String::strchr(s, ' ');
	EXPECT_STREQ(second, " Del Rey");

	const char* st = "Hello";
    const char* res = String::strchr(st, '\0');

    //ASSERT_NE(res, nullptr);
    //EXPECT_EQ(*res, nullptr);
}

TEST(StringFunction, strstr) {
    
	const char* str = "Arctic Monkeys band";
    const char* result = String::strstr(str, "Monkeys");
    
    EXPECT_STREQ(result, "Monkeys band");
	
	const char* s = "Lana Del Rey";
    const char * res = String::strstr(s, "Lana");

    EXPECT_STREQ(res, "Lana Del Rey");
}
