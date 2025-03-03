#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[54][54];
string s;
int visited[54][54];
int dp[54][54];


int go(int y, int x) {
    if(a[y][x] == 'H') {
        return 0;
    }
    if(y < 0 || x < 0 || y >= n || x >= m) {
        return 0;
    }
    if(visited[y][x] == 1) {
        return 987654321;
    }

    visited[y][x] = 1;
    int &ret = dp[y][x];
    if(ret != -1) {
        visited[y][x] = 0;    
        return ret;
    }

    int q = go(y-int(a[y][x] - '0'), x);

    int w = go(y, x+int(a[y][x] - '0'));

    int e = go(y+int(a[y][x] - '0'), x);

    int r = go(y, x-int(a[y][x] - '0'));
    
    ret = max({q, w, e, r}) + 1;

    visited[y][x] = 0;


    return ret;
}


// 테이블 dp[y][x] = 이동횟수
// 점화식 dp[이전위치] = max(dp[현재위치]) + 1
// 초기화 0으로

// 다시 돌아오면 -1
// 오버플로우나 H를 만나면 게임끝

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    int cnt = go(0, 0);
    if(cnt >= 3000) {
        cout << -1 << "\n";
    }
    else {
        cout << cnt << "\n";
    }
}