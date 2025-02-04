#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll t;

bool check(ll a) {

    if(a == 0 || a == 1) {
        return false;
    }

    for(int i = 2; i <= sqrt(a); i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> t;

        while(true) {
            if(check(t) == true) {
                cout << t << "\n";
                break;
            }
            t++;
        }
    }
}