#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string addSpaces(const std::string& s, const std::vector<int>& spaces) {
        std::string result;
        int spaceIndex = 0; // Pointer to iterate through spaces array

        for (int i = 0; i < s.size(); ++i) {
            // If the current index matches the space index, add a space
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result += ' ';
                ++spaceIndex; // Move to the next space index
            }
            result += s[i]; // Add the current character
        }

        return result;
    }
};

int gain() {
    Solution solution;

    // Example 1
    std::string s1 = "LeetcodeHelpsMeLearn";
    std::vector<int> spaces1 = {8, 13, 15};
    std::cout << solution.addSpaces(s1, spaces1) << std::endl;

    // Example 2
    std::string s2 = "icodeinpython";
    std::vector<int> spaces2 = {1, 5, 7, 9};
    std::cout << solution.addSpaces(s2, spaces2) << std::endl;

    // Example 3
    std::string s3 = "spacing";
    std::vector<int> spaces3 = {0, 1, 2, 3, 4, 5, 6};
    std::cout << solution.addSpaces(s3, spaces3) << std::endl;

    return 0;
}
