#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int dp[14];

int go(int here) {
    if(here == 1) {
        return 1;
    }
    if(here == 2) {
        return 2;
    }
    if(here == 3) {
        return 4;
    }

    int &ret = dp[here];
    if(ret != -1) {
        return ret;
    }

    return ret = go(here-1) + go(here-2) + go(here-3);
}

int main() {
    cin >> t;

    memset(dp, -1, sizeof(dp));

    while(t--) {
        cin >> n;

        cout << go(n) << "\n";
    }

}