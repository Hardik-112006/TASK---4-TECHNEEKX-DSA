// LeetCode 36: Valid Sudoku
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> seen;

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char num = board[r][c];
            if (num == '.') continue;

            string rowKey = string(1, num) + " in row " + to_string(r);
            string colKey = string(1, num) + " in col " + to_string(c);
            string boxKey = string(1, num) + " in box " +
                            to_string(r / 3) + "-" + to_string(c / 3);

            if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                return false;
            }

            seen.insert(rowKey);
            seen.insert(colKey);
            seen.insert(boxKey);
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << boolalpha << isValidSudoku(board) << '\n'; // true
    return 0;
}
