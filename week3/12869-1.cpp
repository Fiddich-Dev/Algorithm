#include <bits/stdc++.h>
using namespace std;

struct A {
    int q;
    int w;
    int e;
};

int n;
int a[3];
A atk[6] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1}
};
int dp[64][64][64];


int go(int q, int w, int e) {
    if(q == 0 && w == 0 && e == 0) {
        return 0;
    }

    int &ret = dp[q][w][e];
    if(ret != -1) {
        return ret;
    }

    int temp = 1e9;
    for(A next : atk) {
        temp = min(temp, go(max(0, q - next.q), max(0, w - next.w), max(0, e - next.e)));
    }
    return ret = temp + 1;
}



int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    // 테이블 : dp[현재체력][현재체력][현재체력] = 공격횟수
    // 점화식 : dp[현재체력][현재체력][현재체력] = min(dp[현재체력][현재체력][현재체력] - atk) + 1
    // 초기화 : dp[0][0][0] = 0;

    cout << go(a[0], a[1], a[2]) << "\n";
}