#include <bits/stdc++.h>
using namespace std;

int n;
string s;
// 비트로 표현
int aa[24];
int ret = 1e9;

int solve() {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            // T를 발견하면
            if(aa[j] & (1 << i)) {
                cnt++;
            }
        }

        if(cnt > n/2) {
            cnt = n - cnt;
        }
        sum += cnt;
    }
    return sum;
}

// T의 최소 개수
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == 'T') {
                aa[i] += (1 << j);
            }
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                aa[j] = ~aa[j];
            } 
        }

        ret = min(ret, solve());

        // 원복
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                aa[j] = ~aa[j];
            } 
        }
    }

    cout << ret << "\n";
}