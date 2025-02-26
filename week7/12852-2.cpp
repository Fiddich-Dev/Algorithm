#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000004];
int pre[1000004];

int go(int here) {
    if(here == 1) {
        return 0;
    }

    int &ret = dp[here];
    if(ret != -1) {
        return ret;
    }

    int a = 987654321;
    int b = 987654321;
    int c = 987654321;

    if(here % 3 == 0) {
        a = go(here / 3) + 1;
    }
    if(here % 2 == 0) {
        b = go(here / 2) + 1;
    }
    c = go(here - 1) + 1;

    ret = min({a, b, c});
    if(ret == a) {
        pre[here] = here / 3;
    }
    if(ret == b) {
        pre[here] = here / 2;
    }
    if(ret == c) {
        pre[here] = here - 1;
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    cout << go(n) << "\n";
    
    cout << n << " ";
    for(int i = n; i != 1; i = pre[i]) {
        cout << pre[i] << " ";
    }
    cout << "\n";
}