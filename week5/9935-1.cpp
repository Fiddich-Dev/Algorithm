#include <bits/stdc++.h>
using namespace std;

string s1, s2;
string ret;

int main() {
    cin >> s1;
    cin >> s2;

    for(int i = 0; i < s1.size(); i++) {
        ret += s1[i];
        if(ret.size() >= s2.size()) {
            if(ret.substr(ret.size() - s2.size()) == s2) {
                ret.erase(ret.size() - s2.size());
            }
        }
    }

    if(ret.size()) {
        cout << ret << "\n";
    }
    else {
        cout << "FRULA\n";
    }
}