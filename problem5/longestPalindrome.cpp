/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 示例 1：
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 * 示例 2：
 * 输入: "cbbd"
 * 输出: "bb"
 */
#include <iostream>
#include <string>
#include "../define.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string& s) {
        int length = s.length();
        if (length <= 1){
            return s;
        }
        bool db[length][length];

        unsigned int maxStart = 0, maxEnd = 0;
        for (unsigned end = 0; end < length; ++end) {
            for (unsigned int start = 0; start <= end; ++start) {
                if (start == end){
                    db[start][end] = true;
                }else if(start + 1 == end){
                    db[start][end] = (s.substr(start, 1) == s.substr(end, 1));
                }else{
                    db[start][end] = (db[start + 1][end - 1]) && (s.substr(start, 1) == s.substr(end, 1));
                }
                if (db[start][end] && (end - start > maxEnd - maxStart)){
                    maxStart = start;
                    maxEnd = end;
                }
            }
        }

        return s.substr(maxStart, maxEnd - maxStart + 1);
    }
};

#ifdef TEST_PROBLEM5

int main(){
    string string1 = "babad";
    string string2 = "cbbd";

    Solution solution;

    cout << solution.longestPalindrome(string1) << endl;
    cout << solution.longestPalindrome(string2) << endl;

    return 0;
}

#endif