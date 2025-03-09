#include <bits/stdc++.h>
using namespace std;

int n;
int temp;
vector<int> v;
int ret[1000004];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(ret, -1, sizeof(ret));
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    stack<int> stk;

    for(int i = 0; i < n; i++) {

        while(stk.size() && v[stk.top()] < v[i]) {
            ret[stk.top()] = v[i];
            stk.pop();
        }
        stk.push(i);

    }

    for(int i = 0; i < n; i++) {
        cout << ret[i] << " ";
    }
    cout << "\n";
    
}