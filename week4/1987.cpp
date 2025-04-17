#include <bits/stdc++.h>
using namespace std;

int r, c;
string s;
char a[24][24];
int visited[24][24];
int check;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ret;

void go(int y, int x, int depth) {

    // 비트 켜기
    check |= (1 << (a[y][x] - 'A'));
    visited[y][x] = 1;
    ret = max(ret, depth);

    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
            continue;
        }

        // 방문한적 없는 알파벳일때
        if(visited[ny][nx] == 0 && (check & (1 << (a[ny][nx] - 'A'))) == false) {
            go(ny, nx, depth+1);
            // 비트 끄기
            check &= ~(1 << (a[ny][nx] - 'A'));
            visited[ny][nx] = 0;
        }
    }
}

int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> s;
        for(int j = 0; j < c; j++) {
            a[i][j] = s[j];
        }
    }

    go(0, 0, 1);

    cout << ret << "\n";
}