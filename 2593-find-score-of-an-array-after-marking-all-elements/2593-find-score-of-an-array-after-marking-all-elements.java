import java.util.*;

public class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        boolean[] marked = new boolean[n];
        long score = 0;

        // Pair elements with their indices and sort by value
        List<int[]> pairs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pairs.add(new int[] { nums[i], i });
        }
        pairs.sort(Comparator.comparingInt(a -> a[0]));

        // Process each element in sorted order
        for (int[] pair : pairs) {
            int value = pair[0];
            int index = pair[1];

            // Skip if already marked
            if (marked[index]) {
                continue;
            }

            // Add value to score and mark the element and its adjacent elements
            score += value;
            marked[index] = true;
            if (index > 0) {
                marked[index - 1] = true;
            }
            if (index < n - 1) {
                marked[index + 1] = true;
            }
        }

        return score;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        int[] nums1 = {2, 1, 3, 4, 5, 2};
        System.out.println(solution.findScore(nums1)); // Output: 7

        // Example 2
        int[] nums2 = {2, 3, 5, 1, 3, 2};
        System.out.println(solution.findScore(nums2)); // Output: 5
    }
}
