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
    EXPECT_TRUE(false);
}

TEST(StringFunction, strncmp) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false);
}
