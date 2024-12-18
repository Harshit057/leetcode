public class Solution {
    public static int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];

        for (int i = 0; i < n; i++) {
            answer[i] = prices[i];
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int[] prices1 = {8, 4, 6, 2, 3};
        int[] prices2 = {1, 2, 3, 4, 5};
        int[] prices3 = {10, 1, 1, 6};

        System.out.println(java.util.Arrays.toString(finalPrices(prices1))); // Output: [4, 2, 4, 2, 3]
        System.out.println(java.util.Arrays.toString(finalPrices(prices2))); // Output: [1, 2, 3, 4, 5]
        System.out.println(java.util.Arrays.toString(finalPrices(prices3))); // Output: [9, 0, 1, 6]
    }
}
