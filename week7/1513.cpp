#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int tempY, tempX;
int a[54][54];
int visited[54][54];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int cnt;

int dp[54][54][54][54];

// 만약 다음 좌표가 now+1이면 now += 1을 하고 계속 진행
// 만약 다음 좌표가 0이면 now그대로 진행
// 만약 다음 좌표가 0도 아니고 now+1도 아니면 불가능
int go(int y, int x, int cnt, int now) {
    // 좌표를 벗어날때
    if(y >= n || x >= m) {
        return 0;
    }
    if(y == n-1 && x == m-1) {
        if(cnt == 0 && a[y][x] == 0) {
            return 1;
        }
        if(cnt == 1 && a[y][x] > now) {
            return 1;
        }
    }
    

    int &ret = dp[y][x][cnt][now];
    if(ret != -1) {
        return ret;
    }

    ret = 0;

    if(a[y][x] == 0) {
        ret = (go(y+1, x, cnt, now) + go(y, x+1, cnt, now)) % 1000007;
    }
    else if(a[y][x] > now) {
        ret = (go(y+1, x, cnt-1, a[y][x]) + go(y, x+1, cnt-1, a[y][x])) % 1000007;
    }

    return ret;
}



int main() {
    cin >> n >> m >> c;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < c; i++) {
        cin >> tempY >> tempX;
        tempY--;
        tempX--;
        cnt++;
        a[tempY][tempX] = cnt;
    }


    // 테이블 : dp[y][x][방문해야하는 오락실 개수][방문한 오락실 번호] = 경우의 수
    // 점화식 : dp[y][x][a][b] = dp[y-1][x][a][b] + dp[y][x-1][a][b]
    // 초기화 : dp[]
    for(int i = 0; i <= c; i++) {
        cout << go(0, 0, i, 0) << " "; 
    }

    cout << "\n";

}