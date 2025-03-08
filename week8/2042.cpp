#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<ll> v;
ll temp;
ll a, b, c;
vector<ll> tree;

void update(int index, ll value) {
    while(index <= n) {
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

    tree.resize(n+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        update(i+1, v[i]);
    }

    for(int i = 0; i < m+k; i++) {
        cin >> a >> b >> c;
        // b번째 수를 c로 바꾸기
        if(a == 1) {
            update(b, c-v[b-1]);
            v[b-1] = c;
        }
        // b번째 부터 c번째 까지 더하기
        else if(a == 2) {
            cout << sum(c) - sum(b-1) << "\n";
        }
    }
}