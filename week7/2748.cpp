#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[94];

ll fibo(int m) {
    // 기저사례
    if(m == 0) {
        return 0;
    }
    if(m == 1) {
        return 1;
    }
    // 메모이제이션
    ll &ret = dp[m];
    if(ret != -1) {
        return ret;
    }

    // 로직
    return ret = fibo(m-1) + fibo(m-2);
}

// 탑다운
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    // 초기화
    memset(dp, -1, sizeof(dp));

    cout << fibo(n) << "\n";
}