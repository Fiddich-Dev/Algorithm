#include <bits/stdc++.h>
using namespace std;

int n;
char a[68][68];
string s;
vector<char> v;

bool check(int y, int x, int size) {
    char first = a[y][x];

    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(a[i][j] != first) {
                return false;
            }
        }
    }
    return true;
}

void go(int y, int x, int size) {

    if(size == 1) {
        cout << a[y][x];
        return;
    }
    if(check(y, x, size)) {
        cout << a[y][x];
        return;
    }
    cout << "(";
    go(y, x, size/2);
    go(y, x + size/2, size/2);
    go(y + size/2, x, size/2);
    go(y + size/2, x + size/2, size/2);
    cout << ")";

    
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            a[i][j] = s[j];
        }
    }

    go(0, 0, n);
    cout << "\n";
}