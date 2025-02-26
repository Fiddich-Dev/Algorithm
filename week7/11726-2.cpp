#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int dp[1004];

int go(int here) {
    if(here == 1) {
        return here;
    }
    if(here == 2) {
        return here;
    }

    int &ret = dp[here];
    if(ret != -1) {
        return ret;
    }

    return ret = (go(here - 1) + go(here - 2)) % 10007;

}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    cout << go(n) << "\n";
}