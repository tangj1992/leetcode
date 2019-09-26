/**
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
 * 返回这三个数的和。假定每组输入只存在唯一答案。
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "../define.h"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); ++i) {
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target){
                    return sum;
                } else if(sum < target){
                    ++start;
                }else {
                    --end;
                }

                if (abs(sum - target) < abs(res - target)){
                    res = sum;
                }
            }
        }
        return res;
    }
};

#ifdef TEST_PROBLEM16

int main(){
    vector<int> nums1 = {-1, 2, 1, -4};
    vector<int> nums2 = {1, 1, 1, 0};
    vector<int> nums3 = {0, 2, 1, -3};
    Solution solution;

//    cout<< solution.threeSumClosest(nums1, 1) << endl;
//    cout<< solution.threeSumClosest(nums2, -100) << endl;
    cout<< solution.threeSumClosest(nums3, 1) << endl;

    return 0;
}

#endif