#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100004];
int dp[100004];
int temp1, temp2;

int go(int here) {

    if(here == 0) {
        return 0;
    }

    int &ret = dp[here];
    if(ret != -1) {
        return ret;
    }

    return ret = go(here - 1) + a[here];
}


// dp[n]은 n번까지의 합
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        cout << go(temp2) - go(temp1 - 1) << "\n";
    }

}