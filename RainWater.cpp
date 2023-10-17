#include <iostream>
#include <vector>
using namespace std;
int trapRainWater(const vector<int>& heights) {
    int n = heights.size();
    if (n <= 2) {
        return 0;
    }

    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = heights[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    }

    rightMax[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    }

    int totalWater = 0;
    for (int i = 1; i < n - 1; i++) {
        totalWater += max(0, min(leftMax[i], rightMax[i]) - heights[i]);
    }

    return totalWater;
}

int main() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total trapped water: " << trapRainWater(heights) <<endl;

    return 0;
}
