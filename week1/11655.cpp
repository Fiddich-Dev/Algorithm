#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        // 대문자일때
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A' + 13) % 26 + 'A';
        }
        // 소문자일때
        else if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] - 'a' + 13) % 26 + 'a';
        }
        // 그외
        else {
            continue;
        }
    }

    cout << s << "\n";
}