#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Check if the reversed half is equal to the original half
        // For odd-digit numbers, ignore the middle digit by dividing reversedHalf by 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int gain() {
    Solution solution;

    // Test case 1
    int x1 = 121;
    std::cout << (solution.isPalindrome(x1) ? "true" : "false") << std::endl; // Output: true

    // Test case 2
    int x2 = -121;
    std::cout << (solution.isPalindrome(x2) ? "true" : "false") << std::endl; // Output: false

    // Test case 3
    int x3 = 10;
    std::cout << (solution.isPalindrome(x3) ? "true" : "false") << std::endl; // Output: false

    return 0;
}

