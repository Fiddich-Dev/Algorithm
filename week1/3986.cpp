#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int ret;

void check(string s) {
    stack<char> stk;
    for(int i = 0; i < s.size(); i++) {
        if(stk.size()) {
            if(stk.top() == s[i]) {
                stk.pop();
                continue;
            }
        }
        stk.push(s[i]);
    }

    if(stk.empty()) {
        ret++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        check(s);
    }

    cout << ret << "\n";
}