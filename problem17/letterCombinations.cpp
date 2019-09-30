/**
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 * 示例:
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 */
#include <iostream>
#include <vector>
#include <map>
#include "../define.h"
using namespace std;

class Solution {
public:
    map<string, vector<string>> dict = {
            {"2", {"a", "b", "c"}},
            {"3", {"d", "e", "f"}},
            {"4", {"g", "h", "i"}},
            {"5", {"j", "k", "l"}},
            {"6", {"m", "n", "o"}},
            {"7", {"p", "q", "r", "s"}},
            {"8", {"t", "u", "v"}},
            {"9", {"w", "x", "y", "z"}},
    };
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0){
            return result;
        }
        string digit = digits.substr(0, 1);
        vector<string> string1 = dict[digit];

        if (digits.length() == 1){
            vector<string> string1 = dict[digit];
            for (string str1 : string1) {
                result.push_back(str1);
            }
            return result;
        }

        vector<string> string2 =  letterCombinations(digits.substr(1,digits.length()-1));

        for (string str1 : string1) {
            for (string str2 : string2) {
                result.push_back(str1 + str2);
            }
        }
        return result;
    }
};

#ifdef TEST_PROBLEM17

int main(){
    Solution solution;

    vector<string> result = solution.letterCombinations("23");

    for (string res : result) {
        cout << res << endl;
    }

}

#endif