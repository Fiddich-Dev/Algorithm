#include <bits/stdc++.h>
using namespace std;

int a[13][13];
int ret = 1e9;
int n = 10;
int shape[8];

// 색종이를 붙일 수 있으면 true
bool check(int y, int x, int value) {
    // 범위 안에 있고
    if(y + value - 1 < n && x + value - 1 < n) {
        // 모두 1 이어야 함
        for(int i = y; i < y + value; i++) {
            for(int j = x; j < x + value; j++) {
                if(a[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

// 색종이 붙이기
void solve1(int y, int x, int value) {
    for(int i = y; i < y + value; i++) {
        for(int j = x; j < x + value; j++) {
            a[i][j] = 0;
        }
    }
}
// 색종이 떼기
void solve2(int y, int x, int value) {
    for(int i = y; i < y + value; i++) {
        for(int j = x; j < x + value; j++) {
            a[i][j] = 1;
        }
    }
}

// cnt는 붙인 색종이
void dfs(int y, int x, int cnt) {
    if(y == n) {
        ret = min(ret, cnt);
        return;
    }

    int nx = x+1 == n ? 0 : x+1;
    int ny = nx == 0 ? y+1 : y;

    if(a[y][x] == 0) {
        dfs(ny, nx, cnt);
        return;
    }

    // 색종이 붙이기 큰거부터
    for(int i = 5; i >= 1; i--) {

        // 붙일 수 있는지 확인
        if(check(y, x, i) == true) {
            if(shape[i] == 5) {
                continue;
            }

            // 색종이 붙이기
            solve1(y, x, i);
            shape[i]++;

            dfs(ny, nx, cnt+1);

            // 색종이 떼기
            solve2(y, x, i);
            shape[i]--;

        }
    }
}

int main() {

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }

    
    dfs(0, 0, 0);
    
	cout << (ret == 1e9 ? -1 : ret) << "\n";

}