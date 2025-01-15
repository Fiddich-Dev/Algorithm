#include <bits/stdc++.h>
using namespace std;

int n;
int x;
int a[100004];
int l, r;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;

    l = 0;
    r = n-1;

    sort(a, a + n);

    while(l < r) {
        if(a[l] + a[r] == x) {
            ret++;
            l++;
        }
        else if(a[l]+ a[r] > x) {
            r--;
        }
        else if(a[l]+ a[r] < x) {
            l++;
        }
    }
    
    cout << ret << "\n";
}

// 1 2 3 5 7 9 10 11 12