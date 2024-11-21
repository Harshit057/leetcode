#include <iostream>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        int sign = (x < 0) ? -1 : 1;  // Check the sign of x
        
        // Work with the absolute value of x
        x = abs(x);
        
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow before updating reversed
            if (reversed > (std::numeric_limits<int>::max() / 10) || 
                (reversed == std::numeric_limits<int>::max() / 10 && digit > 7)) {
                return 0;
            }

            reversed = reversed * 10 + digit;
        }
        
        // Apply the sign
        return sign * reversed;
    }
};

int gain() {
    Solution solution;
    
    int x = 123;  // Example input
    int result = solution.reverse(x);
    std::cout << "Reversed: " << result << std::endl;  // Output: 321
    
    x = -123;  // Example input
    result = solution.reverse(x);
    std::cout << "Reversed: " << result << std::endl;  // Output: -321
    
    x = 120;  // Example input
    result = solution.reverse(x);
    std::cout << "Reversed: " << result << std::endl;  // Output: 21

    return 0;
}

