#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[104];
int dp[10004];


int go(int num) {

    if(num == 0) {
        return 0;
    }
    if(num < 0) {
        return 1e9;
    }

    int &ret = dp[num];
    if(ret != -1) {
        return ret;
    }

    int temp = 1e9;
    for(int i = 0; i < n; i++) {
        temp = min(temp, go(num - a[i]));
    }
    return ret = temp + 1;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 테이블 : dp[가치] = 동전의 개수
    // 점화식 : dp[n] = min(dp[n-1], dp[n-5], dp[n-12]) + 1)
    // 초기화 : dp[0] = 0

    memset(dp, -1, sizeof(dp));

    int ret = go(k);
    if(ret >= 1e9) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }

    cout << dp[k] << "\n";

}