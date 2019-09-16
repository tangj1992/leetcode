/**
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 *
 * 示例 1:
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 *
 * 示例 2:
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 *
 * 示例 3:
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 *
 * 示例 4:
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 *
 * 示例 5:
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 */

#include <iostream>
#include <string>
#include "../define.h"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

    bool isMatch(const char* s, const char* p) {
        if(*p == 0) return *s == 0;

        auto first_match = *s && (*s == *p || *p == '.');

        if(*(p+1) == '*'){
            return isMatch(s, p+2) || (first_match && isMatch(++s, p));
        }
        else{
            return first_match && isMatch(++s, ++p);
        }
    }
};

#ifdef TEST_PROBLEM10

int main(){
    Solution solution;
    cout << solution.isMatch("aaa", "ab*a*c*a") << endl;
    cout << solution.isMatch("abcd", "d*") << endl;
    cout << solution.isMatch("aaa", "ab*a") << endl;
    cout << solution.isMatch("a", "") << endl;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("ab", ".*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
    cout << solution.isMatch("mississippi", "mis*is*p*.") << endl;

    return 0;
}

#endif