import java.util.*;

public class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
            // Find the index of the first occurrence of the minimum value
            int minIndex = 0;
            for (int j = 1; j < nums.length; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            // Replace the minimum value with its product with the multiplier
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
}
