import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        // Create a memoization map
        Map<String, Integer> memo = new HashMap<>();
        return calculate(nums, 0, 0, target, memo);
    }

    private int calculate(int[] nums, int index, int currentSum, int target, Map<String, Integer> memo) {
        // Base case: if we've processed all numbers
        if (index == nums.length) {
            return currentSum == target ? 1 : 0;
        }
        
        // Create a unique key for memoization
        String key = index + "," + currentSum;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }
        
        // Recursive calls: add and subtract the current number
        int add = calculate(nums, index + 1, currentSum + nums[index], target, memo);
        int subtract = calculate(nums, index + 1, currentSum - nums[index], target, memo);
        
        // Store result in memo
        memo.put(key, add + subtract);
        return memo.get(key);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        int[] nums1 = {1, 1, 1, 1, 1};
        int target1 = 3;
        System.out.println(solution.findTargetSumWays(nums1, target1)); // Output: 5

        // Example 2
        int[] nums2 = {1};
        int target2 = 1;
        System.out.println(solution.findTargetSumWays(nums2, target2)); // Output: 1
    }
}
