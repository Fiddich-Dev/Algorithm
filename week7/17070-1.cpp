#include <bits/stdc++.h>
using namespace std;

int n;
int a[17][17];
// 0은 가로, 1은 세로, 2는 대각선
int dp[17][17][3];

int go(int y, int x, int con) {
    // 벽때문에 방해되는경우
    if(con == 0) {
        if(a[y][x] == 1) {
            return 0;
        }
    }
    if(con == 1) {
        if(a[y][x] == 1) {
            return 0;
        }
    }
    if(con == 2) {
        if(a[y][x] == 1 || a[y-1][x] == 1 || a[y][x-1] == 1) {
            return 0;
        }
    }

    // 목적지에 도착했을때
    if(y == n-1 && x == n-1) {
        return 1;
    }
    // 오버플로우 체크
    if(y > n-1 || x > n-1) {
        return 0;
    }

    // 메모이 제이션
    int &ret = dp[y][x][con];
    if(ret != -1) {
        return ret;
    }

    // 현재방향이 가로
    if(con == 0) {
        int a = go(y, x+1, 0);
        int b = go(y+1, x+1, 2);

        return ret = a + b;
        // return go(y, x+1, 0) + go(y+1, x+1, 2);
    }
    // 현재방향이 세로
    else if(con == 1) {
        int a = go(y+1, x, 1);
        int b = go(y+1, x+1, 2);

        return ret = a + b;

        // return go(y+1, x, 1) + go(y+1, x+1, 2);
    }
    // 현재방향이 대각선
    else {
        int a = go(y, x+1, 0);
        int b = go(y+1, x, 1);
        int c = go(y+1, x+1, 2);

        return ret = a + b + c;

        // return go(y, x+1, 0) + go(y+1, x, 1) + go(y+1, x+1, 2);
    }
}

// 파이프가 가로일때 2가지  가로 or 대각선 됨
// 파이프가 세로일때 2가지  세로 or 대각선됨
// 파이프가 대각선일때 3거자  가로 or 세로 or 대각선됨
// 파이프의 앞쪽이 n-1넘으면 안됨


// 테이블 dp[파이프의 위치][파이프의 방향] = 목적지에 가는 방법 수
// 점화식 dp[이전 파이프 위치][이전 파이프 방향] = dp[현재 파이프 위치][현재 파이프 방향] + 목적지 가는 경우의 수
// 초기화 파이프 위치가 (n-1, n-1)이면 return 1

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << go(0, 1, 0) << "\n";


}