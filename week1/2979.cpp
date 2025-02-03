#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int x, y;
int t[104];

int ret;

int main() {
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++) {
        cin >> x >> y;
        for(int j = x; j < y; j++) {
            t[j]++;
        }
    }

    for(int i = 0; i < 104; i++) {
        if(t[i] == 3) {
            ret += c * t[i];
        }
        else if(t[i] == 2) {
            ret += b * t[i];
        }
        else if(t[i] == 1) {
            ret += a * t[i];
        }
        else {
            continue;
        }
    }
    cout << ret << "\n";
}