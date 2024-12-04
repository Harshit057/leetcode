class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Preprocess t to create a map of characters to their indices
        unordered_map<char, vector<int>> charIndices;
        for (int i = 0; i < t.size(); i++) {
            charIndices[t[i]].push_back(i);
        }

        // Check if s is a subsequence using binary search
        int prevIndex = -1;
        for (char c : s) {
            if (charIndices.find(c) == charIndices.end()) {
                return false; // Character not found in t
            }
            // Binary search for the first index > prevIndex
            auto it = upper_bound(charIndices[c].begin(), charIndices[c].end(), prevIndex);
            if (it == charIndices[c].end()) {
                return false; // No valid index found
            }
            prevIndex = *it; // Update the previous index
        }

        return true;
    }
};

