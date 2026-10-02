// LeetCode 347: Top K Frequent Elements
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    vector<pair<int, int>> items; // {value, frequency}
    for (auto& entry : freq) {
        items.push_back({entry.first, entry.second});
    }

    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first; // deterministic tie-break
    });

    vector<int> answer;
    for (int i = 0; i < k && i < (int)items.size(); i++) {
        answer.push_back(items[i].first);
    }
    return answer;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n'; // 1 2
    return 0;
}
