#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer to track the position for elements not equal to val

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Place the element at the position k
                k++; // Increment the pointer
            }
        }

        return k; // Return the count of elements not equal to val
    }
};
