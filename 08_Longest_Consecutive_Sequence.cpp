// LeetCode 128: Longest Consecutive Sequence
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> values(nums.begin(), nums.end());
    int longest = 0;

    for (int x : values) {
        // Start counting only at the beginning of a sequence.
        if (values.count(x - 1) == 0) {
            int current = x;
            int length = 1;

            while (values.count(current + 1)) {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << '\n'; // 4
    return 0;
}
