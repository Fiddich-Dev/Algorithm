#include <bits/stdc++.h>
using namespace std;

int n;
int visited[4000004];
vector<int> v;

int s, e, sum;
int ret;

int main() {
    cin >> n;

    for(int i = 2; i <= n; i++) {
        if(visited[i] == 1) {
            continue;
        }
        for(int j = i*2; j <= n; j += i) {
            visited[j] = 1; 
        }
    }

    for(int i = 2; i <= n; i++) {
        if(visited[i] == 0) {
            v.push_back(i);
        }
    }

    while(e < v.size()) {
        if(sum < n) {
            sum += v[e];
            e++;
        }
        else if(sum > n) {
            sum -= v[s];
            s++;
        }
        else if(sum == n) {
            ret++;
            sum -= v[s];
            s++;
        }
    }

    if(v.size() && v[v.size() - 1] == n) {
        ret++;
    }

    cout << ret << "\n";
    
}