#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100004];
int dp[100004];
int temp1, temp2;

// dp[n]은 n번까지의 합
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        dp[i] = sum;
    }

    dp[0] = 0;

    for(int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        cout << dp[temp2] - dp[temp1 - 1] << "\n";
    }
}