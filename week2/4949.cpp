#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
    stack<char> stk;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            stk.push(s[i]);
        }
        else if(s[i] == '[') {
            stk.push(s[i]);
        }

        else if(s[i] == ')') {
            if(stk.size() && stk.top() == '(') {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }

        else if(s[i] == ']') {
            if(stk.size() && stk.top() == '[') {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
    }
    if(stk.size()) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true) {
        getline(cin, s);

        if(s == ".") {
            break;
        }

        if(check(s) == true) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
        

    }
}