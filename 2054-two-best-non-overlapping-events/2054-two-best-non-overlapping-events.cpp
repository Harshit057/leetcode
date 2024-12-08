#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events based on their end times
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> dp(n); // dp[i] stores the max value achievable up to the i-th event
        dp[0] = events[0][2]; // Initialize with the value of the first event

        // Build the dp array
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1], events[i][2]);
        }

        int maxSum = dp[0]; // Initialize max sum with one event

        // Function to find the latest non-overlapping event
        auto findLastNonOverlapping = [&](int index) {
            int low = 0, high = index - 1, best = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (events[mid][1] < events[index][0]) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return best;
        };

        // Calculate max sum with at most two events
        for (int i = 0; i < n; ++i) {
            // Consider the current event
            int currentValue = events[i][2];

            // Find the best non-overlapping event
            int lastNonOverlapping = findLastNonOverlapping(i);
            if (lastNonOverlapping != -1) {
                currentValue += dp[lastNonOverlapping];
            }

            // Update the maximum sum
            maxSum = max(maxSum, currentValue);
        }

        return maxSum;
    }
};
