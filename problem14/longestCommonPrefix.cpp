/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 *
 * 示例 2:
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 *
 * 说明:
 * 所有输入只包含小写字母 a-z 。
 */
#include <iostream>
#include <string>
#include <vector>
#include "../define.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size() <= 0){
            return result;
        }
        if (strs.size() == 1){
            return strs[0];
        }
        int length = 1;
        string temp;

        while (length <= strs[0].length()){
            temp = strs[0].substr(0, length);
            for (int i = 1; i < strs.size(); ++i) {
                if(strs[i].substr(0, length) != temp){
                    return result;
                }
            }
            ++length;
            result = temp;
        }

        return result;
    }
};

#ifdef TEST_PROBLEM14

int main(){
    Solution solution;
    vector<string> vector1({"flower","flow","flight"});
    vector<string> vector2({"dog","racecar","car"});
    vector<string> vector3({"c","c","c"});

//    cout << solution.longestCommonPrefix(vector1) << endl;
//    cout << solution.longestCommonPrefix(vector2) << endl;
    cout << solution.longestCommonPrefix(vector3) << endl;



    return 0;
}

#endif