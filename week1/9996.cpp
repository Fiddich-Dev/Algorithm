#include <bits/stdc++.h>
using namespace std;

int n;
string p;
string s;
string pre, suf;

string check(string s) {
    if(s.size() < pre.size() + suf.size()) {
        return "NE";
    }
    else if(s.substr(0, pre.size()) == pre && s.substr(s.size() - suf.size(), suf.size()) == suf) {
        return "DA";
    }
    else {
        return "NE";
    }
}

int main() {
    cin >> n;
    cin >> p;
    
    auto it = find(p.begin(), p.end(), '*');
    int idx = distance(p.begin(), it);
    pre = p.substr(0, idx);
    suf = p.substr(idx+1);

    for(int i = 0; i < n; i++) {
        cin >> s;
        cout << check(s) << "\n";
    }
}