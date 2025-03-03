#include <bits/stdc++.h>
using namespace std;

int t, w;
int a[1004];
int dp[1004][32][4];
int ret = -987654321;


// 테이블 dp[시간][움직인횟수][위치] = 받은 자두개수
// 점화식 dp[현재시간][현재움직인 횟수][현재위치] = max(dp[이전시간][이전움직인 횟수][이전위치]) + a[현재시간] == 현재위치 ? 1 : 0 
// 초기화 dp[0][0][1] = (a[0] == 1 ? 1 : 0), dp[0][1][2] = (a[0] == 2 ? 1 : 0)
int main() {
    cin >> t >> w;
    for(int i = 0; i < t; i++) {
        cin >> a[i];
    }

    dp[0][0][1] = (a[0] == 1 ? 1 : 0);
    dp[0][1][2] = (a[0] == 2 ? 1 : 0);

    // 시간이 지날때 마다
    for(int i = 1; i < t; i++) {
        // 움직인 횟수에 따라서
        for(int j = 0; j <= w; j++) {

            // 1에 있을때
            if(j == 0) {
                dp[i][j][1] = dp[i-1][j][1] + (a[i] == 1 ? 1 : 0);
            }
            else {
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]) + (a[i] == 1 ? 1 : 0);    
            }

            // 2에 있을때
            if(j == 0) {
                // 불가능한 경우
                // dp[i][j][2] = dp[i-1][j][2] + (a[i] == 2 ? 1 : 0);
                continue;
            }
            else {
                dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2]) + (a[i] == 2 ? 1 : 0);    
            }

            ret = max(dp[i][j][1], dp[i][j][2]);
        }
    }

    for(int i = 0; i <= w; i++) {
        ret = max(ret, dp[t-1][i][1]);
        ret = max(ret, dp[t-1][i][2]);
    }

    cout << ret << "\n";

}