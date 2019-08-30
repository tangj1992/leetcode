/**
* 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
* 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
*
* 示例：
* 给定 nums = [2, 7, 11, 15], target = 9
* 因为 nums[0] + nums[1] = 2 + 7 = 9
* 所以返回 [0, 1]
*/
#include <iostream>
#include <vector>
#include "../define.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

#ifdef TEST_PROBLEM1

int main(){
    vector<int> arr({2, 7, 11, 15});
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(arr, target);

    for (int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }

    return 0;
}

#endif