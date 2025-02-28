#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[16][16];
int dp[16][1 << 16];

int go(int here, int visited) {
    if(visited == (1 << n) - 1) {
        return a[here][0] ? a[here][0] : 987654321;
    }

    int &ret = dp[here][visited];
    if(ret != -1) {
        return ret;
    }

    int m = 987654321;

    for(int i = 1; i < n; i++) {
        if(visited & (1 << i)) {
            continue;
        }
        if (a[here][i] == 0) {
            continue; 
        }
        m = min(m, go(i, visited | (1 << i)) + a[here][i]);

        // m = min(m, go(i, visited | (1 << i)) + (a[here][i] ? a[here][i] : 987654321));
    }

    return ret = m;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << go(0, 1) << "\n";

}