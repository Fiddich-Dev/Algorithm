#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> v;
int temp;

vector<int> ret[10];

void go(int s, int e, int level) {
    if(level == k) {
        return;
    }
    int mid = (s + e) / 2;

    ret[level].push_back(v[mid]);
    go(s, mid-1, level+1);
    go(mid+1, e, level+1);
}

int main() {
    cin >> k;
    for(int i = 0; i < (1 << k)-1; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    go(0, v.size()-1, 0);

    for(int i = 0; i < k; i++) {
        for(int j : ret[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}