// LeetCode 1: Two Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> indexOf;

    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];

        if (indexOf.count(complement)) {
            return {indexOf[complement], i};
        }
        indexOf[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);

    cout << '[';
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ", ";
        cout << ans[i];
    }
    cout << "]\n"; // [0, 1]
    return 0;
}
