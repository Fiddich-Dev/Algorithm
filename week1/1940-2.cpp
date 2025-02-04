#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
vector<int> v;
int ret;

int combi(int start, vector<int> &b) {
    int cnt = 0;

    if(b.size() == 2) {
        int sum = 0;
        for(int j : b) {
            sum += j;
        }
        if(sum == m) {
            return 1;
        }
        return 0;
    }
    
    for(int i = start+1; i < n; i++) {
        b.push_back(v[i]);
        cnt += combi(i, b);
        b.pop_back();
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> b;
    ret = combi(-1, b);

    cout << ret << "\n";
}