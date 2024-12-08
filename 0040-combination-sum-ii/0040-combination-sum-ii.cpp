#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and facilitate pruning
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            // Found a valid combination
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                // Skip duplicates
                continue;
            }
            
            if (candidates[i] > target) {
                // Stop further recursion as the candidates are sorted
                break;
            }
            
            combination.push_back(candidates[i]); // Include the current candidate
            backtrack(candidates, target - candidates[i], i + 1, combination, result); // Move to the next candidate
            combination.pop_back(); // Backtrack
        }
    }
};

