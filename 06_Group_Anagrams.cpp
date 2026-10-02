
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        vector<int> freq(26, 0);

        // Step 1: Count frequency
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Create key using frequency
        string key = "";

        for (int i = 0; i < 26; i++) {
            key += to_string(freq[i]) + "#";
        }

        // Step 3: Group words using key
        mp[key].push_back(s);
    }

    // Step 4: Store groups in answer
    vector<vector<string>> ans;

    for (auto it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    vector<vector<string>> ans = groupAnagrams(strs);

    for (auto group : ans) {
        cout << "[ ";
        for (string s : group) {
            cout << s << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}