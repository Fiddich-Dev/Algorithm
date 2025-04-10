#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int cnt;
int ret;


void go(int y, int x, int size) {

    // cout << y << " : " << x << "\n";

    if(y == r && x == c) {
        ret = cnt;
        return;
    }

    if(size == 1) {
        return;
    }
    
    if(r < y + size/2 && c < x + size/2) {
        // cnt = cnt;
        go(y, x, size / 2);
    }
    else if(r < y + size/2 && c >= x + size/2) {
        cnt = cnt + size/2 * size/2;
        go(y, x + size / 2, size / 2);
    }
    else if(r >= y + size/2 && c < x + size/2) {
        cnt = cnt + 2 * size/2 * size/2;
        go(y + size / 2, x, size / 2);
    }
    else if(r >= y + size/2 && c >= x + size/2) {
        cnt = cnt + 3 * size/2 * size/2;
        go(y + size / 2, x + size / 2, size / 2);
    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;

    go(0, 0, (1 << n));

    cout << ret << '\n';
    cout << cnt << '\n';

}
// 1사분면 일때
// y, x + size/2 

// 2사분면 일때
// y, x + size/2 

// 3사분면 일때
// y, x + size/2 

// 4사분면 일때
// y, x + size/2 