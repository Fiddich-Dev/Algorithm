#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int m1, m2;

int c;
int p;
int p1, p2;

// dp[돈] = 칼로리
int dp[10004];


int main() {

    while(true) {
        scanf("%d %d.%d", &n, &m1, &m2);

        int m = m1 * 100 + m2;
        
        // 칼로리
        vector<int> v1;
        // 가격
        vector<int> v2;

        if(n == 0 && m == 0) {
            break;
        }

        for(int i = 0; i < n; i++) {
            scanf("%d %d.%d", &c, &p1, &p2);
            
            p = p1 * 100 + p2;
            v1.push_back(c);
            v2.push_back(p);
        }

        fill(&dp[0], &dp[0]+10004, 0);

        for(int i = 0; i < n; i++) {
            for(int j = v2[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - v2[i]] + v1[i]);
            }
        }
        
        cout << dp[m] << "\n";
    }


    // 테이블 : dp[돈] = 칼로리
    // 점화식 : dp[num] = max(dp[num - 700] + 7.00, dp[num - 199] + 2.00)
    // 초기화 : dp[0] = 0
}