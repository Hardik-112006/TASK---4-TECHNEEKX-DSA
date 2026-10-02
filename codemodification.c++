
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int arr[] = {4, 7, 4, 2, 9, 7, 4, 1, 9, 3};
    int n = 10;

    unordered_map<int, int> freq;
    vector<int> order;

    int hashSteps = 0;

    // 1. Frequency count + first occurrence order
    for (int i = 0; i < n; i++) {
        hashSteps++;

        if (freq.find(arr[i]) == freq.end()) {
            order.push_back(arr[i]);
        }

        freq[arr[i]]++;
    }

    cout << "Frequencies:\n";
    for (int x : order) {
        hashSteps++;
        cout << x << " -> " << freq[x] << endl;
    }

    // 2. Mode: maximum frequency, tie -> smaller number
    int mode = arr[0];
    int maxFreq = 0;

    for (int x : order) {
        hashSteps++;

        if (freq[x] > maxFreq ||
            (freq[x] == maxFreq && x < mode)) {
            maxFreq = freq[x];
            mode = x;
        }
    }

    cout << "Mode: " << mode
         << ", Count: " << maxFreq << endl;

    // 3. First non-repeating element
    int firstNonRepeating = -1;

    for (int x : order) {
        hashSteps++;

        if (freq[x] == 1) {
            firstNonRepeating = x;
            break;
        }
    }

    if (firstNonRepeating == -1) {
        cout << "First non-repeating: None\n";
    } else {
        cout << "First non-repeating: "
             << firstNonRepeating << endl;
    }

    // 4. Nested loop comparison count
    int nestedSteps = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nestedSteps++;
            if (arr[i] == arr[j]) {
                // Frequency comparison
            }
        }
    }

    cout << "Nested loop comparisons: "
         << nestedSteps << endl;

    cout << "HashMap loop iterations: "
         << hashSteps << endl;

    return 0;
}