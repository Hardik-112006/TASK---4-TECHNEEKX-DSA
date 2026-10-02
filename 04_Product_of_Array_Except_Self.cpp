// LeetCode 238: Product of Array Except Self
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> answer(n, 1);

    int prefix = 1;
    for (int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--) {
          suffix *= nums[i+1];
        answer[i] *= suffix;
      
    }
    return answer;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n'; // 24 12 8 6
    return 0;
}
