import java.util.*;

public class Solution {
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        // Step 1: Create adjacency list to represent the tree
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }

        // Step 2: Initialize component count
        int[] componentCount = new int[1]; // Single-element array to allow pass-by-reference

        // Step 3: Start DFS from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of k-divisible components
        return componentCount[0];
    }

    private int dfs(int currentNode, int parentNode, List<List<Integer>> adjList, int[] values, int k, int[] componentCount) {
        int sum = 0;

        // Traverse all neighbors
        for (int neighborNode : adjList.get(currentNode)) {
            if (neighborNode != parentNode) { // Avoid traversing back to parent
                sum += dfs(neighborNode, currentNode, adjList, values, k, componentCount);
                sum %= k; // Keep the remainder within range
            }
        }

        // Add the current node's value
        sum += values[currentNode];
        sum %= k; // Keep the remainder within range

        // If the sum modulo k is 0, it forms a valid component
        if (sum == 0) {
            componentCount[0]++;
            return 0; // Return 0 to "detach" this subtree
        }

        // Otherwise, return the remaining sum to the parent
        return sum;
    }

    public static void main(String[] args) {
        Solution solver = new Solution();

        // Example 1
        int n1 = 5;
        int[][] edges1 = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
        int[] values1 = {1, 8, 1, 4, 4};
        int k1 = 6;
        System.out.println(solver.maxKDivisibleComponents(n1, edges1, values1, k1)); // Output: 2

        // Example 2
        int n2 = 7;
        int[][] edges2 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
        int[] values2 = {3, 0, 6, 1, 5, 2, 1};
        int k2 = 3;
        System.out.println(solver.maxKDivisibleComponents(n2, edges2, values2, k2)); // Output: 3
    }
}
