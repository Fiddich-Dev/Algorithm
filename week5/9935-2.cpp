#include <bits/stdc++.h>
using namespace std;

string s1, s2;
string ret;

stack<char> stk;

int main() {
    cin >> s1;
    cin >> s2;

    for(int i = 0; i < s1.size(); i++) {
        stk.push(s1[i]);

        string temp = "";

        if(stk.size() >= s2.size()) {
            if(stk.top() == s2[s2.size() - 1]) {
                for(int j = 0; j < s2.size(); j++) {
                    temp += stk.top();
                    stk.pop();
                }
            }
        }

        reverse(temp.begin(), temp.end());

        if(temp != s2) {
            for(int j = 0; j < temp.size(); j++) {
                stk.push(temp[j]);
            }
        }
    }


    if(stk.size()) {

        

        while (stk.size()){ 
            ret += stk.top();
            stk.pop();
        }
        reverse(ret.begin(), ret.end());

        cout << ret << "\n";
    }
    else{
        cout << "FRULA\n";
    }
    
}