#include <bits/stdc++.h>
using namespace std;

int n;
int a[1004];
int len;
int lis[1004];

int main() {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        auto pos = lower_bound(lis, lis + len, a[i]);
        if(*pos == 0) {
            len++;
        }
        *pos = a[i];
    }

    cout << len << "\n";
}

