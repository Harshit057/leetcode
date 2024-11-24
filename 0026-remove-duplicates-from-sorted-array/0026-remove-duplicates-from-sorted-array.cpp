#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle edge case

        int k = 1; // Pointer to track the position for the next unique element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Found a unique element
                nums[k] = nums[i]; // Move it to position k
                k++; // Increment the unique count
            }
        }

        return k; // Return the count of unique elements
    }
};
