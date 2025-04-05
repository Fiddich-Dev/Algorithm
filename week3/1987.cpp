#include <bits/stdc++.h>
using namespace std;

int r, c;
string s;
char a[24][24];
int visited[24][24];
int check[26];
int ret = -1e9;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void go(int y, int x, int cnt) {

    ret = max(ret, cnt);

    if(check[a[y][x] - 'A'] == 1) {
        return;
    }

    visited[y][x] = 1;
    check[a[y][x] - 'A'] = 1;
    

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
            continue;
        }
        if(visited[ny][nx] == 0 && check[a[ny][nx] - 'A'] == 0) {

            go(ny, nx, cnt+1);

            visited[ny][nx] = 0;
            check[a[ny][nx] - 'A'] = 0;
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