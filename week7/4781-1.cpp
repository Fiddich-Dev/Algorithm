#include <bits/stdc++.h>
using namespace std;

int n;
float m;
int c;
float p;

// dp[돈] = 칼로리
int dp[10004];


int main() {

    while(true) {
        cin >> n >> m;
        
        // 칼로리
        vector<int> v1;
        // 가격
        vector<int> v2;

        if(n == 0 && m == 0.00) {
            break;
        }
        m = round(m * 100);

        for(int i = 0; i < n; i++) {
            cin >> c >> p;
            p = round(p * 100);
            v1.push_back(c);
            v2.push_back(p);
        }

        fill(&dp[0], &dp[0]+10004, -1e9);
        dp[0] = 0;
        int ret = -1e9;

        for(int i = 0; i < n; i++) {
            for(int j = v2[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - v2[i]] + v1[i]);
                ret = max(ret, dp[j]);
            }
        }

        cout << ret << "\n";

    }


    // 테이블 : dp[돈] = 칼로리
    // 점화식 : dp[num] = max(dp[num - 700] + 7.00, dp[num - 199] + 2.00)
    // 초기화 : dp[0] = 0
}