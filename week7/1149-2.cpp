#include <bits/stdc++.h>
using namespace std;

int n;
int a[1004][5];
int dp[1004][5];


int go(int here, int color) {
    if(here == 1 && color == 1) {
        return a[here][color];
    }
    if(here == 1 && color == 2) {
        return a[here][color];
    }
    if(here == 1 && color == 3) {
        return a[here][color];
    }

    int &ret = dp[here][color];
    if(ret != -1) {
        return ret;
    }

    if(color == 1) {
        return ret = min(go(here-1, 2), go(here-1, 3)) + a[here][color];
    }
    else if(color == 2) {
        return ret = min(go(here-1, 1), go(here-1, 3)) + a[here][color];
    }
    else {
        return ret = min(go(here-1, 1), go(here-1, 2)) + a[here][color];
    }
    
}


int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }

    cout << min({go(n, 1), go(n, 2), go(n, 3)}) << "\n";
}