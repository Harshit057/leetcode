#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long totalSum = 0; // To store the total sum of elements
        int minAbsValue = INT_MAX; // To track the smallest absolute value in the matrix
        int negativeCount = 0; // To count the number of negative elements

        // Traverse the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value = matrix[i][j];
                totalSum += abs(value); // Add absolute value to the total sum
                if (value < 0) {
                    negativeCount++; // Count negatives
                }
                minAbsValue = min(minAbsValue, abs(value)); // Track minimum absolute value
            }
        }

        // If the count of negative numbers is odd, subtract twice the smallest absolute value
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsValue;
        }

        return totalSum;
    }
};

