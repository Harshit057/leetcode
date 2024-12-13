import java.util.Arrays;

public class Solution {
    public int maximumBeauty(int[] nums, int k) {
        // Sort the array
        Arrays.sort(nums);
        int n = nums.length;

        // Initialize sliding window pointers
        int start = 0, maxBeauty = 0;

        // Sliding window to find the maximum beauty
        for (int end = 0; end < n; end++) {
            // Ensure the range [nums[start], nums[end]] satisfies the condition
            while (nums[end] - nums[start] > 2 * k) {
                start++;
            }
            // Update the maximum beauty
            maxBeauty = Math.max(maxBeauty, end - start + 1);
        }

        return maxBeauty;
    }
}

