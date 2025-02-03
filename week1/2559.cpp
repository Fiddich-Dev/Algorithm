#include <bits/stdc++.h>
using namespace std;

int n, k;
int psum[100004];
int num;
int ret = -987654321;

int main() {
    cin >> n >> k;
    psum[0] = 0;
    // 1번 인덱스부터 저장
    for(int i = 1; i <= n; i++) {
        cin >> num;
        psum[i] = psum[i-1] + num;
    }

    for(int i = 0; i < n-k+1; i++) {
        ret = max(ret, psum[k+i] - psum[i]);
    }

    cout << ret << "\n";
}