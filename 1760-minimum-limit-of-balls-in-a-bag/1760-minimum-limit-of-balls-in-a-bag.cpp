#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canDivide(const vector<int>& nums, int penalty, int maxOperations) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                // Calculate required splits
                operations += (balls - 1) / penalty;
            }
            if (operations > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                result = mid;  // Mid is a feasible penalty
                right = mid - 1;  // Try smaller penalties
            } else {
                left = mid + 1;  // Increase penalty
            }
        }

        return result;
    }
};

// Example main function
int gain() {
    Solution sol;
    vector<int> nums = {2, 4, 8, 2};
    int maxOperations = 4;
    cout << "Minimum penalty: " << sol.minimumSize(nums, maxOperations) << endl;
    return 0;
}
