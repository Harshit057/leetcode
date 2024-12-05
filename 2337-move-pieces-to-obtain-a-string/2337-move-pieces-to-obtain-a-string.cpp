#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        // Remove all '_' characters and check if the remaining characters match
        string filteredStart, filteredTarget;
        for (char c : start) {
            if (c != '_') filteredStart += c;
        }
        for (char c : target) {
            if (c != '_') filteredTarget += c;
        }

        if (filteredStart != filteredTarget) return false;

        int n = start.size();
        int i = 0, j = 0;

        // Check if L and R pieces can move to their correct positions
        while (i < n && j < n) {
            // Skip '_' in start and target
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            // If either pointer goes out of bounds, break
            if (i == n || j == n) break;

            // Check if the characters at i and j are aligned
            if (start[i] != target[j]) return false;

            // Verify movement rules
            if (start[i] == 'L' && i < j) return false; // 'L' can only move left
            if (start[i] == 'R' && i > j) return false; // 'R' can only move right

            i++;
            j++;
        }

        return true;
    }
};

int gain() {
    Solution solution;

    string start = "_L__R__R_";
    string target = "L______RR";
    cout << (solution.canChange(start, target) ? "true" : "false") << endl;

    start = "R_L_";
    target = "__LR";
    cout << (solution.canChange(start, target) ? "true" : "false") << endl;

    start = "_R";
    target = "R_";
    cout << (solution.canChange(start, target) ? "true" : "false") << endl;

    return 0;
}

