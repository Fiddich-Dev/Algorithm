#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[104];
int dp[10004];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(&dp[0], &dp[0]+10004, 1e9);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = a[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }

    if(dp[k] == 1e9) {
        cout << -1 << "\n";
    }
    else {
        cout << dp[k] << "\n";
    }
}