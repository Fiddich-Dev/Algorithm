#include <bits/stdc++.h>
using namespace std;

int n;

bool che[4000001];
int a[2000001];
int p;
int lo, hi;
int ret;
int sum;

int s, e;

vector<int> v;

int main() {
    cin >> n;

    for(int i = 2; i <= n; i++) {
        if(che[i]) {
            continue;
        }
        for(int j = 2 * i; j <= n; j += i) {
            che[j] = 1;
        }
    }

    for(int i = 2; i <= n; i++) {
        if(che[i] == 0) {
            v.push_back(i);
        }
    }

    while(hi < v.size()) {
        if(sum < n) {
            sum += v[hi];
            hi++;
        }
        else if(sum > n) {
            sum -= v[lo];
            lo++;
        }
        else {
            ret++;
            sum -= v[lo];
            lo++;
        }
    }

    if(v.size() && v[v.size() - 1] == n) {
        ret++;
    }


    cout << ret << "\n";
    
}