#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int solve(int n) {
    int cnt2 = 0;
    int cnt5 = 0;

    int now = 2;
    while(now <= n) {
        cnt2 += n / now;
        now *= 2;
    }

    now = 5;
    while(now <= n) {
        cnt5 += n / now;
        now *= 5; 
    }

    return min(cnt2, cnt5);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << solve(n) << "\n";
    }
    
}