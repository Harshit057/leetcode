#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate the area for the current pair of lines
            int currentArea = std::min(height[left], height[right]) * (right - left);
            maxArea = std::max(maxArea, currentArea);

            // Move the pointer corresponding to the shorter line
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxArea;
    }
};

int gain() {
    Solution solution;

    // Example 1
    std::vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << solution.maxArea(height1) << std::endl; // Output: 49

    // Example 2
    std::vector<int> height2 = {1, 1};
    std::cout << solution.maxArea(height2) << std::endl; // Output: 1

    return 0;
}
