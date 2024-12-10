#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        unordered_map<string, int> substringCount;

        // Traverse through the string
        for (int i = 0; i < n; ++i) {
            string currentSubstring;
            for (int j = i; j < n; ++j) {
                // Only extend the substring if it's still special
                if (currentSubstring.empty() || s[j] == currentSubstring.back()) {
                    currentSubstring.push_back(s[j]);
                    substringCount[currentSubstring]++;
                } else {
                    break;
                }
            }
        }

        // Find the longest special substring with frequency >= 3
        int maxLength = -1;
        for (const auto& entry : substringCount) {
            if (entry.second >= 3) {
                maxLength = max(maxLength, (int)entry.first.length());
            }
        }

        return maxLength;
    }
};
