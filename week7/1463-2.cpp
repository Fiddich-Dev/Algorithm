#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000004];

int go(int here) {
    if(here == 0) {
        return 1e9;
    }
    if(here == 1) {
        return 0;
    }

    int &ret = dp[here];
    if(ret != -1) {
        return ret;
    }

    int a = 1e9;
    int b = 1e9;
    int c = go(here-1) + 1;

    if(here % 3 == 0) {
        a = go(here/3) + 1;
    }
    if(here % 2 == 0) {
        b = go(here/2) + 1;
    }

    return ret = min({a, b, c});
}

int main() {
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << go(n) << "\n";
}