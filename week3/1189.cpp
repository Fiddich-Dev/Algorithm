#include <bits/stdc++.h>
using namespace std;

int r, c, k;
char a[8][8];
int visited[8][8];
string s;
int ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int y, int x, int depth) {

    // visited[y][x] = 1;
    if(depth > k) {
        return;
    }

    if(y == 0 && x == c-1) {
        if(depth == k) {
            ret++;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
            continue;
        }
        if(visited[ny][nx] == 0 && a[ny][nx] == '.') {
            visited[ny][nx] = 1 ;
            go(ny, nx, depth+1);
            visited[ny][nx] = 0;
        }
    }
}

// 시작점 : r-1, 0
// 도착점 : 0, c-1
int main() {
    cin >> r >> c >> k;

    for(int i = 0; i < r; i++) {
        cin >> s;
        for(int j = 0; j < c; j++) {
            a[i][j] = s[j];
        }
    }
    visited[r-1][0] = 1;
    go(r-1, 0, 1);

    cout << ret << "\n";
}
