#include <bits/stdc++.h>
using namespace std;

int n;
int temp;
vector<int> v;
int dp[304][5];

// dp[n][1] = max(dp[n-2][1], dp[n-2][2]) + v[n]
// dp[n][2] = dp[n-1][1] + v[n]
int main() {
    cin >> n;
    v.push_back(0);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    dp[1][1] = v[1];
    dp[1][2] = -1e9; // 안되는 경우
    dp[2][1] = v[2];
    dp[2][2] = v[1] + v[2];

    for(int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + v[i];
        dp[i][2] = dp[i-1][1] + v[i];
    }

    cout << max(dp[n][1], dp[n][2]) << "\n";
}