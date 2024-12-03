#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        int m = s.size();
        int n = p.size();
        
        // dp[i][j] indicates whether s[0..i-1] matches p[0..j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns with '*' that can match zero preceding characters
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Characters match or pattern has '.'
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' matches zero occurrences
                    dp[i][j] = dp[i][j - 2];
                    // '*' matches one or more occurrences
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};

int gain() {
    Solution solution;
    
    // Example 1
    std::string s1 = "aa";
    std::string p1 = "a";
    std::cout << (solution.isMatch(s1, p1) ? "true" : "false") << std::endl; // Output: false
    
    // Example 2
    std::string s2 = "aa";
    std::string p2 = "a*";
    std::cout << (solution.isMatch(s2, p2) ? "true" : "false") << std::endl; // Output: true
    
    // Example 3
    std::string s3 = "ab";
    std::string p3 = ".*";
    std::cout << (solution.isMatch(s3, p3) ? "true" : "false") << std::endl; // Output: true
    
    return 0;
}
