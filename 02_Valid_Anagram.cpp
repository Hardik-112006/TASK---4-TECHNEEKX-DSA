// LeetCode 242: Valid Anagram
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (char c : t) {
        if (freq[c] == 0) return false;
        freq[c]--;
    }
    return true;
}

int main() {
    string s = "anagram", t = "nagaram";
    cout << boolalpha << isAnagram(s, t) << '\n'; // true
    return 0;
}
