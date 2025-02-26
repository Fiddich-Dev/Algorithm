#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[100];

ll fibo(int here) {
    // 기저사례
    if(here == 0) {
        return 0;
    }
    if(here == 1) {
        return 1;
    }
    // 메모이제이션
    ll &ret = dp[here];
    if(ret != -1) {
        return ret;
    }
    // 로직
    return ret = fibo(here-1) + fibo(here-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 초기화
    memset(dp, -1, sizeof(dp));

    cin >> n;

    cout << fibo(n) << "\n";

}