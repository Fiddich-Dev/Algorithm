#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, c;
int ret;


ll go(int n) {
    if(n == 1) {
        return a % c;
    }
    
    if(n % 2 == 1) {
        return (((go(n/2) * go(n/2)) % c) * (a % c)) % c;
    }
    else {
        return (go(n/2) * go(n/2)) % c;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    
    ret = go(b);

    cout << ret << "\n";

}