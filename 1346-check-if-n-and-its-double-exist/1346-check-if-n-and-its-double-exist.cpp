#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {
        std::unordered_set<int> seen;
        
        for (int num : arr) {
            // Check if 2 * num or num / 2 (if divisible) exists in the set
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }
        
        return false;
    }
};

int gain() {
    Solution solution;
    
    // Test case 1
    std::vector<int> arr1 = {10, 2, 5, 3};
    std::cout << (solution.checkIfExist(arr1) ? "true" : "false") << std::endl; // Output: true
    
    // Test case 2
    std::vector<int> arr2 = {3, 1, 7, 11};
    std::cout << (solution.checkIfExist(arr2) ? "true" : "false") << std::endl; // Output: false

    return 0;
}
