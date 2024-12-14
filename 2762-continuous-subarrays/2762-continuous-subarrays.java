import java.util.TreeMap;

class Solution {
    public long continuousSubarrays(int[] nums) {
        // TreeMap to maintain sorted frequency map of current window
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        int left = 0;
        long count = 0;

        for (int right = 0; right < nums.length; right++) {
            // Add current element to the frequency map
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);

            // While the window violates the condition |max - min| > 2
            while (freq.lastEntry().getKey() - freq.firstEntry().getKey() > 2) {
                // Remove leftmost element from the frequency map
                freq.put(nums[left], freq.get(nums[left]) - 1);
                if (freq.get(nums[left]) == 0) {
                    freq.remove(nums[left]);
                }
                left++;
            }

            // Add the count of all valid subarrays ending at `right`
            count += right - left + 1;
        }

        return count;
    }
}
