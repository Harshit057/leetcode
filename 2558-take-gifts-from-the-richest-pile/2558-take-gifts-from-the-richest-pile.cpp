#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Use a max-heap (priority queue) to always pick the largest pile
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        // Perform k operations
        for (int i = 0; i < k; ++i) {
            int maxGifts = maxHeap.top(); // Get the maximum pile
            maxHeap.pop();               // Remove it from the heap
            int remaining = floor(sqrt(maxGifts)); // Calculate the remaining gifts
            maxHeap.push(remaining);    // Push the remaining gifts back into the heap
        }

        // Sum up the remaining gifts in all piles
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }

        return totalGifts;
    }
};

// Main function for testing
int gain() {
    Solution sol;
    vector<int> gifts1 = {25, 64, 9, 4, 100};
    int k1 = 4;
    cout << "Output for Example 1: " << sol.pickGifts(gifts1, k1) << endl;

    vector<int> gifts2 = {1, 1, 1, 1};
    int k2 = 4;
    cout << "Output for Example 2: " << sol.pickGifts(gifts2, k2) << endl;

    return 0;
}
