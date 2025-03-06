#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
ll temp;
vector<ll> v;
ll a, b, c;
vector<ll> tree;

void update(int index, ll value) {
    while(index <= tree.size()-1) {
        tree[index] += value;
        index += index & -index;
    }
}

ll sum(int index) {
    ll ret = 0;
    while(index >= 1) {
        ret += tree[index];
        index -= index & -index;
    }
    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    tree.resize(n+1, 0);
    for(int i = 0; i < n; i++) {
        update(i+1, v[i]);
    }
    
    for(int i = 0; i < m+k; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(b, c - v[b-1]);
            v[b-1] = c;
        }
        else if(a == 2) {
            cout << sum(c) - sum(b-1) << "\n";
        }
    }
}