#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Minimum number of obstacles to remove for each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        // Deque for 0-1 BFS
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Check if the new cell is within bounds
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int new_dist = dist[x][y] + grid[nx][ny];
                    
                    // If a shorter path is found, update the distance
                    if (new_dist < dist[nx][ny]) {
                        dist[nx][ny] = new_dist;

                        // Add to the deque based on weight
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};

int ain() {
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << sol.minimumObstacles(grid1) << endl; // Output: 2

    // Example 2
    vector<vector<int>> grid2 = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
    cout << sol.minimumObstacles(grid2) << endl; // Output: 0

    return 0;
}
