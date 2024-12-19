public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Start from the end of nums1 and nums2
        int p1 = m - 1; // Pointer for nums1
        int p2 = n - 1; // Pointer for nums2
        int p = m + n - 1; // Pointer for placing elements in nums1

        // Merge nums2 into nums1
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // If there are remaining elements in nums2, copy them
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int m = 3;
        int[] nums2 = {2, 5, 6};
        int n = 3;
        solution.merge(nums1, m, nums2, n);
        System.out.println("Example 1 Output: " + java.util.Arrays.toString(nums1)); // [1, 2, 2, 3, 5, 6]

        // Example 2
        nums1 = new int[]{1};
        m = 1;
        nums2 = new int[]{};
        n = 0;
        solution.merge(nums1, m, nums2, n);
        System.out.println("Example 2 Output: " + java.util.Arrays.toString(nums1)); // [1]

        // Example 3
        nums1 = new int[]{0};
        m = 0;
        nums2 = new int[]{1};
        n = 1;
        solution.merge(nums1, m, nums2, n);
        System.out.println("Example 3 Output: " + java.util.Arrays.toString(nums1)); // [1]
    }
}
