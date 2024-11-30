#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <deque>
#include <algorithm> // For reverse()

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Graph representation: adjacency list
        unordered_map<int, deque<int>> graph;
        unordered_map<int, int> out_degree, in_degree;

        // Build the graph and compute in-degrees and out-degrees
        for (auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            out_degree[start]++;
            in_degree[end]++;
        }

        // Find the starting node for the Eulerian path
        int start_node = pairs[0][0]; // Default to the first node
        for (auto& [node, out] : out_degree) {
            if (out > in_degree[node]) {
                start_node = node;
                break;
            }
        }

        // Hierholzer's algorithm to find Eulerian path
        stack<int> stack;
        vector<int> path;
        stack.push(start_node);

        while (!stack.empty()) {
            int node = stack.top();
            if (!graph[node].empty()) {
                int next_node = graph[node].front();
                graph[node].pop_front();
                stack.push(next_node);
            } else {
                path.push_back(node);
                stack.pop();
            }
        }

        // Reverse the path to construct the result
        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};

int ain() {
    Solution solution;

    vector<vector<int>> pairs1 = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    vector<vector<int>> pairs2 = {{1, 3}, {3, 2}, {2, 1}};
    vector<vector<int>> pairs3 = {{1, 2}, {1, 3}, {2, 1}};

    auto result1 = solution.validArrangement(pairs1);
    auto result2 = solution.validArrangement(pairs2);
    auto result3 = solution.validArrangement(pairs3);

    auto printResult = [](const vector<vector<int>>& result) {
        for (const auto& pair : result) {
            cout << "[" << pair[0] << ", " << pair[1] << "] ";
        }
        cout << endl;
    };

    printResult(result1); // Output: [[11, 9], [9, 4], [4, 5], [5, 1]]
    printResult(result2); // Output: [[1, 3], [3, 2], [2, 1]]
    printResult(result3); // Output: [[1, 2], [2, 1], [1, 3]]

    return 0;
}

