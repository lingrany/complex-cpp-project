#include "gtest/gtest.h"
#include "string_processor.h"

// 创建一个测试固件
class StringProcessorTest : public ::testing::Test {
protected:
    StringProcessor processor;
};

// 测试元音字母计数功能
TEST_F(StringProcessorTest, TestCountVowels) {
    EXPECT_EQ(processor.countVowels("hello"), 2);
    EXPECT_EQ(processor.countVowels("HELLO"), 2);
    EXPECT_EQ(processor.countVowels("bcdfg"), 0);
    EXPECT_EQ(processor.countVowels("aeiou"), 5);
}