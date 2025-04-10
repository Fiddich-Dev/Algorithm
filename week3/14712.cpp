#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[28][28];
int ret;

// 2*2가 만들어지면 true
bool check(int y, int x) {
    if(y >= 1 && x >= 1) {
        if(a[y][x] == 1 && a[y-1][x-1] == 1 && a[y-1][x] == 1 && a[y][x-1] == 1) {
            return true;
        }
    }
    return false;
}

void go(int y, int x) {
    if(y == n) {
        ret++;
        return;
    }

    int nx = x+1 == m ? 0 : x+1;
    int ny = nx == 0 ? y+1 : y;

    // 넴모를 안놓을때
    go(ny, nx);

    // 넴모를 놓을때
    a[y][x] = 1;
    if(check(y, x) == false) {
        go(ny, nx);
    }
    a[y][x] = 0;

}

int main() {
    cin >> n >> m;

    go(0, 0);

    cout << ret << "\n";
}