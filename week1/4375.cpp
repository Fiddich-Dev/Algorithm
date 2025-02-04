#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n) {
        int now = 1;
        int ret = 1;
        while(true) {
            if(now % n == 0) {
                cout << ret << "\n";
                break;
            }
            now = (((now % n) * (10 % n)) % n + 1) % n;
            ret++;
        }
    }
}