#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1010;

int n,m;
int value[N],weight[N];
int dp[N][N];
int f[N];

// 二维背包 dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i])
int dpTwoDim() {
    for (int i=0;i<=m;i++) dp[0][i] = 0;
    for (int i=0;i<=n;i++) dp[i][0] = 0;

    // 枚举每一个物品
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= weight[i]) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }

    return dp[n][m];
}

// 滚动数组优化 dp[j] = max(dp[j],dp[j-weight[j]]+value[j])
int dpOneDim() {
    for (int i=1;i<=n;i++) {
        for (int j=m;j>=weight[i];j--) {
            f[j] = max(f[j],f[j-weight[i]]+value[i]);
        }
    }

    return f[m];
}

/*
 * n=4 m=5
 * 1 2
 * 2 4
 * 3 4
 * 4 5
 */
int main() {
    cin >> n >> m;

    for (int i=1;i<=n;i++) {
        cin >> weight[i] >> value[i];
    }

    std::cout << dpTwoDim() << std::endl;

    std::cout << dpOneDim() << std::endl;

    return 0;
}