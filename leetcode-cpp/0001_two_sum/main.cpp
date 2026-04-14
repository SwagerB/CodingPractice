#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap; // 值 -> 索引
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hashmap.find(complement) != hashmap.end()) {
                return {hashmap[complement], i};
            }
            hashmap[nums[i]] = i;
        }
        return {}; // 题目保证有解，实际不会执行到这里
    }
};

int main() {
    // 示例 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    Solution sol;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "[" << result1[0] << "," << result1[1] << "]" << endl;

    // 示例 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "[" << result2[0] << "," << result2[1] << "]" << endl;

    // 示例 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "[" << result3[0] << "," << result3[1] << "]" << endl;

    return 0;
}