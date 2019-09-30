/**
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
 * 找出所有满足条件且不重复的四元组。
 *
 * 注意：
 * 答案中不可以包含重复的四元组。
 * 示例：
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 *  [-1,  0, 0, 1],
 *  [-2, -1, 1, 2],
 *  [-2,  0, 0, 2]
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "../define.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4);
    }

private:
    vector<vector<int>> kSum(vector<int>& nums, int target, unsigned int k) {
        vector<vector<int>> result;
        if (k == 2){
            int start = 0;
            int end = nums.size() - 1;
            while (start < end){
                int sum = nums[start] + nums[end];
                if (sum == target){
                    result.push_back(vector<int>{nums[start], nums[end]});
                    //去重
                    while (start < end && nums[start] == nums[start + 1]){
                        ++start;
                    }
                    while (start < end && nums[end] == nums[end - 1]){
                        --end;
                    }
                    ++start;
                    --end;
                } else if(sum > target){
                    --end;
                }else{
                    ++start;
                }
            }
            return result;
        }
        vector<int>::iterator num = nums.begin();
        while(num != nums.end()) {
            vector<int> nums2;
            vector<int>::iterator value = num + 1;
            while (value != nums.end() && (*value == *num)){
                ++value;
            }
            nums2.assign(num + 1, nums.end());
            vector<vector<int>> resultDeep = kSum(nums2, target - *num, k - 1);
            if (!resultDeep.empty()){
                for (vector<int> res : resultDeep) {
                    res.push_back(*num);
                    result.push_back(res);
                }
            }
            num = value;
        }


        return result;
    }
};

#ifdef TEST_PROBLEM18

int main(){
//    vector<int> nums = {-3,-2,-1,0,0,1,2,3};
    vector<int> nums = {0,0,0,0};

    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, 0);


    for (vector<int> const res : result) {
        cout << "[";
        for (int num : res) {
            cout << num << ",";
        }
        cout << "]," << endl;
    }

    cout<< endl <<  result.size() << endl;

    return 0;
}

#endif