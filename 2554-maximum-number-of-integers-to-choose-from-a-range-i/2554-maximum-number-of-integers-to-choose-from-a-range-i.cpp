#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banned_set(banned.begin(), banned.end());
        int current_sum = 0, count = 0;

        for (int num = 1; num <= n; ++num) {
            if (banned_set.count(num)) {
                continue;
            }
            if (current_sum + num > maxSum) {
                break;
            }
            current_sum += num;
            count++;
        }

        return count;
    }
};
