#include "string_processor.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int StringProcessor::countVowels(const std::string& text) {
    int count = 0;
    for (char c : text) {
        char lower = std::tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            count++;
        }
    }
    return count;
}

std::string StringProcessor::reverseWords(const std::string& text) {
    if (text.empty()) return text;
    
    std::vector<std::string> words;
    std::string word;
    
    // 分割单词
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    
    // 添加最后一个单词
    if (!word.empty()) {
        words.push_back(word);
    }
    
    // 反转单词顺序
    std::string result;
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) {
            result += " ";
        }
    }
    
    return result;
}

// 这里有一个bug！回文检查没有正确处理大小写和非字母字符
bool StringProcessor::isPalindrome(const std::string& text) {
    if (text.empty()) return true;
    
    int left = 0;
    int right = text.length() - 1;
    
    while (left < right) {
        // 这里有一个bug！没有跳过非字母字符
        if (std::tolower(text[left]) != std::tolower(text[right])) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}