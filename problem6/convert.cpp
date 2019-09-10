/**
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 *
 * 请你实现这个将字符串进行指定行数变换的函数：
 * string convert(string s, int numRows);
 * 示例 1:
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 *
 * 示例 2:
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 */
#include <iostream>
#include <string>
#include <math.h>
#include "../define.h"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1){
            return s;
        }
        //总列数
        int column = ceil(s.length() / (float) (numRows - 1));
        string res;
        int p;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < column; ++j) {
              p = (2 * numRows - 2) * j + i;
              if (p < s.length()){
                  res += s.substr(p, 1);
                  //除了第一行和最后一行,列之间都会多一个元素
                  if (i > 0 && i < numRows - 1){
                    p = p + (numRows - i - 1) * 2;
                    if (p < s.length()){
                        res += s.substr(p, 1);
                    }
                  }
              }
            }
        }
        return res;
    }
};

#ifdef TEST_PROBLEM6

int main(){
    string string1 = "LEETCODEISHIRING";

    Solution solution;


    cout << solution.convert(string1, 3) << endl;
    cout << solution.convert(string1, 4) << endl;

    string string2 = "A";
    cout << solution.convert(string2, 1) << endl;

    return 0;
}

#endif