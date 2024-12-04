class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0; // Pointers for str1 and str2
        int n = str1.size(), m = str2.size();

        // Traverse str1 to check if str2 is a subsequence
        while (i < n && j < m) {
            // Check if characters match or can be made to match
            if (str1[i] == str2[j] || getNextChar(str1[i]) == str2[j]) {
                j++; // Move to the next character in str2
            }
            i++; // Always move to the next character in str1
        }

        // If we matched all characters of str2, return true
        return j == m;
    }

private:
    // Helper function to get the next character cyclically
    char getNextChar(char c) {
        return c == 'z' ? 'a' : c + 1;
    }
};
