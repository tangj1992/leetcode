/**
 * 给定n个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 *
 * 示例:
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 */
#include <iostream>
#include <vector>
#include "../define.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int tempArea = 0;
        int start = 0;
        int end = height.size() - 1;

        while (end > start){
            tempArea = min(height[start], height[end]) * (end - start);
            maxArea = max(tempArea, maxArea);
            if (height[start] > height[end]){
                --end;
            }else{
                ++start;
            }
        }

        return maxArea;
    }

private:
    int min(int num1, int num2){
        return num1 > num2 ? num2 : num1;
    }
    int max(int num1, int num2){
        return num1 > num2 ? num1 : num2;
    }
};

#ifdef TEST_PROBLEM11

int main(){
    Solution solution;

    vector<int> vector1({1, 8, 6, 2, 5, 4, 8, 3, 7});
    cout << solution.maxArea(vector1) << endl;

    return 0;
}

#endif