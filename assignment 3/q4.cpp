#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> mat = {
        {0,1,1,0,1},
        {1,1,0,1,0},
        {0,1,1,1,0},
        {1,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0}
    };

    int n = mat.size(), m = mat[0].size();
    int ans = 0;
    vector<vector<int>> dp = mat;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 1)
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dp[i][j]);

    cout << ans;
    return 0;
}
