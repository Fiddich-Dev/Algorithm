#include <bits/stdc++.h>
using namespace std;

int n;
int temp;
vector<int> v;
int dp[304][5];

int go(int here, int cnt) {
    if(here == 1 && cnt == 1) {
        return v[1];
    }
    if(here == 1 && cnt == 2) {
        return -1e9;
    }
    if(here == 2 && cnt == 1) {
        return v[2];
    }
    if(here == 2 && cnt == 2) {
        return v[1] + v[2];
    }

    int &ret = dp[here][cnt];
    if(ret != -1) {
        return ret;
    }

    if(cnt == 1) {
        return ret = max(go(here-2, 1), go(here-2, 2)) + v[here];
    }
    else {
        return ret = go(here-1, 1) + v[here];
    }
}

// dp[n][1] = max(dp[n-2][1], dp[n-2][2]) + v[n]
// dp[n][2] = dp[n-1][1] + v[n]
int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;
    v.push_back(0);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    cout << max(go(n, 1), go(n, 2)) << "\n";

}