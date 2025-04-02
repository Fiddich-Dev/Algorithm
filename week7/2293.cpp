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

    // 테이블 : dp[동전들의 가치] = 만들수 있는 경우의 수
    // 점화식 : dp[num] = dp[num - 1] + dp[num - 2] + dp[num - 5]
    // 초기화 : dp[0] = 1

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = a[i]; j <= k; j++) {
            dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[k] << "\n";
    
}  