#include <iostream>
#include <string>
#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, sign = 1, result = 0;

        // Step 1: Ignore leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle the sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Check for overflow/underflow before updating result
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // Step 5: Apply the sign
        return result * sign;
    }
};

int gain() {
    Solution solution;
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);
    int ret = solution.myAtoi(s); // Using the Solution class's myAtoi function
    std::cout << "Converted integer: " << ret << std::endl;
    return 0;
}
