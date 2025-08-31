#ifndef STRING_PROCESSOR_H
#define STRING_PROCESSOR_H

#include <string>
#include <vector>

class StringProcessor {
public:
    // 计算字符串中元音字母的数量
    int countVowels(const std::string& text);
    
    // 反转字符串中的单词顺序
    std::string reverseWords(const std::string& text);
    
    // 检查字符串是否为回文（忽略大小写和非字母字符）
    bool isPalindrome(const std::string& text);
};

#endif