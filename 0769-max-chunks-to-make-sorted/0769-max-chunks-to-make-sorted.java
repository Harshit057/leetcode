public class Solution {
    public int maxChunksToSorted(int[] arr) {
        int max = 0;
        int chunks = 0;

        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max, arr[i]);
            // If the maximum value up to this index is equal to the index,
            // we can form a chunk.
            if (max == i) {
                chunks++;
            }
        }

        return chunks;
    }

    public static void main(String[] args) {
        // Example 1
        int[] arr1 = {4, 3, 2, 1, 0};
        System.out.println("Example 1 Output: " + new Solution().maxChunksToSorted(arr1)); // Output: 1

        // Example 2
        int[] arr2 = {1, 0, 2, 3, 4};
        System.out.println("Example 2 Output: " + new Solution().maxChunksToSorted(arr2)); // Output: 4
    }
}
