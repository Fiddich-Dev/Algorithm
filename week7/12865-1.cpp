#include <bits/stdc++.h>
using namespace std;

int n, k;
int w, v;
// 무게
vector<int> v1;
// 가치
vector<int> v2;

int dp[100004];


int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> w >> v;
        v1.push_back(w);
        v2.push_back(v);
    }

    fill(&dp[0], &dp[0] + 100004, 0);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = k; j >= v1[i]; j--) {
            dp[j] = max(dp[j], dp[j - v1[i]] + v2[i]);
        }
    }

    cout << dp[k] << "\n";

    // 테이블 : dp[무게] = 가치
    // 점화식 : dp[num] = max(dp[num - 6] + 13, dp[num - 4] + 8 ...)
    // 초기화 : dp[0] = 0
}