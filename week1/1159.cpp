#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a[26];
string ret;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        a[s[0] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(a[i] >= 5) {
            ret += i + 'a';       
        }
    }

    if(ret.empty()) {
        cout << "PREDAJA\n";
    }
    else {
        cout << ret << "\n";
    }
}