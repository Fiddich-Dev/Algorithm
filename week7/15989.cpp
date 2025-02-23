#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int n;
ll dp[10004];

void solve() {
    // 초기화
    memset(dp, 0, sizeof(dp));
    // 기저사례
    dp[0] = 1;
    // 메모이제이션
    // 로직
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 10000; j++) {
            if(j - i >= 0) {
                dp[j] += dp[j - i];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}
