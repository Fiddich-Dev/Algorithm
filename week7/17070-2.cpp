#include <bits/stdc++.h>
using namespace std;

int n;
int a[17][17];
// 0은 가로, 1은 세로, 2는 대각선
int dp[17][17][3];

bool check(int y, int x, int con) {
    if(con == 0 || con == 1) {
        if(a[y][x] == 0) {
            return true;
        }
    }
    else if(con == 2){
        if(a[y][x] == 0 && a[y-1][x] == 0 && a[y][x-1] == 0) {
            return true;
        }
    }
    return false;
}

// 파이프가 가로일때 2가지  가로 or 대각선 됨
// 파이프가 세로일때 2가지  세로 or 대각선됨
// 파이프가 대각선일때 3거자  가로 or 세로 or 대각선됨
// 파이프의 앞쪽이 n-1넘으면 안됨


// 테이블 dp[파이프의 위치][파이프의 방향] = 목적지에 가는 방법 수
// 점화식 dp[이전 파이프 위치][이전 파이프 방향] = dp[현재 파이프 위치][현재 파이프 방향] + 목적지 가는 경우의 수
// 초기화 파이프 위치가 (n-1, n-1)이면 return 1

int main() {

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    dp[0][1][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {

            if(check(i, j + 1, 0)) {
                dp[i][j + 1][0] += dp[i][j][0];
            }
            if(check(i + 1, j + 1, 2)) {
                dp[i + 1][j + 1][2] += dp[i][j][0]; 
            }

            if(check(i + 1, j, 1)) {
                dp[i + 1][j][1] += dp[i][j][1];
            }
            if(check(i + 1, j + 1, 2)) {
                dp[i + 1][j + 1][2] += dp[i][j][1]; 
            }
            
            if(check(i, j + 1, 0)) {
                dp[i][j + 1][0] += dp[i][j][2];
            }
            if(check(i + 1, j, 1)) {
                dp[i + 1][j][1] += dp[i][j][2];
            }
            if(check(i + 1, j + 1, 2)) {
                dp[i + 1][j + 1][2] += dp[i][j][2];  
            }

        }
    }
    cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2] << "\n";

}

