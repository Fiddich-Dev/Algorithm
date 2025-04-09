#include<bits/stdc++.h>
using namespace std;

int n;
// 체력
int L[24];
// 기쁨
int J[24];
int dp[104];



int go(int num) {

    if(num <= 0) {
        return -1e9;
    }

    int &ret = dp[num];
    if(ret != -1) {
        return ret;
    }

    int temp = 0;
    for(int i = 0; i < n; i++) {
        temp = max(temp, go(num - L[i]) + J[i]);
    }
    cout << temp << "\n";
    return ret = temp;
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> L[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> J[i];
    }

    // 테이블 : dp[체력] = 기쁨
    // 점화식 : dp[num] = max(dp[num - L[i]] + J[i])
    // 초기화 : dp[100] = 0

    for(int i = 0; i < n; i++) {
        for(int j = 100; j > L[i]; j--) {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }
    
    cout << dp[100] << "\n";
}