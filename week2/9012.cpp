#include <bits/stdc++.h>
using namespace std;

int t;
string a;

bool check(string s) {
    stack<char> stk;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            stk.push(s[i]);
        }
        if(s[i] == ')') {
            if(stk.size() && stk.top() == '(') {
                stk.pop();
            }
            else {
                stk.push(')');
            }
        }
    }
    if(stk.size() == 0) {
        return true;
    }
    else {
        return false;
    }
} 

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> a;
        if(check(a) == true) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

