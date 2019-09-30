/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 *
 * 示例 1:
 * 输入: "()"
 * 输出: true
 *
 * 示例 2:
 * 输入: "()[]{}"
 * 输出: true
 *
 * 示例 3:
 * 输入: "(]"
 * 输出: false
 *
 * 示例 4:
 * 输入: "([)]"
 * 输出: false
 *
 * 示例 5:
 * 输入: "{[]}"
 * 输出: true
*/
#include <iostream>
#include <string>
#include <stack>
#include "../define.h"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;

        for (char ch : s){
            if(!charStack.empty() && match(charStack.top(), ch)){
                charStack.pop();
            }else{
                charStack.push(ch);
            }

        }

        return charStack.empty();
    }

private:
    bool match(char char1, char char2){
        switch (char1){
            case '(':
                return char2 == ')';
            case '{':
                return char2 == '}';
            case '[':
                return char2 == ']';
        }

        return false;
    }
};

#ifdef TEST_PROBLEM20
int main(){
    Solution solution;

    cout << solution.isValid("()") << endl;
    cout << solution.isValid("()[]{}") << endl;
    cout << solution.isValid("(]") << endl;
    cout << solution.isValid("([)]") << endl;
    cout << solution.isValid("{[]}") << endl;

    return 0;
}
#endif