#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll s, e;
ll ret;

ll a[100004];

int temp;
vector<int> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    while(e < n) {
        if(a[v[e]] == 0) {
            a[v[e]]++;
            e++;
        }
        else {
            ret += (e - s);
            a[v[s]]--;
            s++;
        }
    }

    ret += (e - s) * (e - s + 1) / 2;

    cout << ret << "\n";
    
}