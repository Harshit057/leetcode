#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sort the array for two-pointer approach
        int closestSum = INT_MAX / 2; // Initialize with a large value

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Update closestSum if the current sum is closer to target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    ++left; // Move left pointer to increase the sum
                } else if (currentSum > target) {
                    --right; // Move right pointer to decrease the sum
                } else {
                    return currentSum; // Exact match found
                }
            }
        }

        return closestSum;
    }
};

// Example usage for testing
int gain() {
    Solution sol;
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Output for Example 1: " << sol.threeSumClosest(nums1, target1) << endl;

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Output for Example 2: " << sol.threeSumClosest(nums2, target2) << endl;

    return 0;
}
