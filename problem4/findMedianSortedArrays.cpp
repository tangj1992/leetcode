/**
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 示例 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 则中位数是 2.0
 *
 * 示例 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 则中位数是 (2 + 3)/2 = 2.5
*/
#include <iostream>
#include <string>
#include <vector>
#include "../define.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();

        int left  = (length1 + length2 + 1) / 2;
        int right = (length1 + length2 + 2) / 2;

        int k1 = getKth(nums1, 0, length1 - 1, nums2, 0, length2 - 1, left);
        int k2 = getKth(nums1, 0, length1 - 1, nums2, 0, length2 - 1, right);

        return (k1 + k2) * 0.5;
    }
private:
    int getMin(int num1, int num2){
        return num1 > num2 ? num2 : num1;
    }
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int length1 = end1 - start1 + 1;
        int length2 = end2 - start2 + 1;
        if(length1 > length2){
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        }
        if(length1 == 0){
            return nums2[start2 + k - 1];
        }
        if (k == 1){
            return getMin(nums1[start1], nums2[start2]);
        }

        int i = start1 + getMin(length1, k / 2) - 1;
        int j = start2 + getMin(length2, k / 2) - 1;

        if (nums1[i] > nums2[j]){
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
        return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    }
};

#ifdef TEST_PROBLEM4

int main(){
    vector<int> nums1({1, 3, 4});
    vector<int> nums2({2});
    vector<int> nums3({1, 2});
    vector<int> nums4({3, 4});
    Solution solution;

    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    cout << solution.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}

#endif
