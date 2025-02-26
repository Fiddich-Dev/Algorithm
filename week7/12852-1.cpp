#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000004];
int pre[1000004];

int main() {
    cin >> n;

    dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        int a = 987654321;
        int b = 987654321;
        int c = 987654321;

        if(i % 3 == 0) {
            a = dp[i/3] + 1;
        }
        if(i % 2 == 0) {
            b = dp[i/2] + 1;
        }
        c = dp[i-1] + 1;

        dp[i] = min({a, b, c});

        if(dp[i] == a) {
            pre[i] = i / 3;
        }
        else if(dp[i] == b) {
            pre[i] = i / 2;
        }
        else {
            pre[i] = i - 1;
        }
    }

    cout << dp[n] << "\n";

    cout << n << " ";
    for(int i = n; i != 1; i = pre[i]) {
        cout << pre[i] << " ";
    }
    cout << "\n";
}