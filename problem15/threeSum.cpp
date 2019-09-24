/**
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组
 *
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 */
#include <iostream>
#include <vector>
#include "../define.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0){
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]){
                //去重
                continue;
            }
            int start = i + 1;
            int end = nums.size() - 1;
            while ( start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == 0){
                    result.push_back(vector<int>{nums[i], nums[start], nums[end]});
                    //去重
                    while (start < end && nums[start] == nums[start + 1]){
                        ++start;
                    }
                    while (start < end && nums[end] == nums[end - 1]){
                        --end;
                    }
                    ++start;
                    --end;
                } else if(sum > 0){
                    --end;
                }else{
                    ++start;
                }
            }
        }
        return result;
    }
};

#ifdef TEST_PROBLEM15

int main(){
    vector<int> nums = {0,0,0,0};

    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    for (vector<int>& outer : result) {
        for (int num : outer) {
            cout << num  << ",";
        }
        cout << endl;
    }

    return 0;
}

#endif