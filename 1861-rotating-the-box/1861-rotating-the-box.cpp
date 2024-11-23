#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // Process each row to simulate gravity
        for (int i = 0; i < m; i++) {
            int emptySpot = n - 1; // Index of the rightmost empty spot
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    // Move the stone to the farthest empty spot
                    swap(box[i][j], box[i][emptySpot]);
                    emptySpot--;
                } else if (box[i][j] == '*') {
                    // Obstacle resets the empty spot pointer
                    emptySpot = j - 1;
                }
            }
        }

        // Rotate the box 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - i - 1] = box[i][j];
            }
        }

        return rotatedBox;
    }
};
