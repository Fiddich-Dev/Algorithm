#include <bits/stdc++.h>
using namespace std;

string s;

// 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
// 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다. // 3개씩 검사
// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.

bool check(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

bool solve(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            return true;
        }
    }
    return false;
}

bool solve1(string s) {
    for(int i = 0; i < s.size() - 2; i++) {
        if((check(s[i]) == true && check(s[i+1]) == true && check(s[i+2]) == true) || (check(s[i]) == false && check(s[i+1]) == false && check(s[i+2]) == false)) {
            return false;
        }
    }
    return true;
}

bool solve2(string s) {
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i+1] && s[i] != 'e' && s[i] != 'o') {
            return false;
        }
    }
    return true;
}


int main() {
    while(true) {
        cin >> s;
        if(s == "end") {
            break;
        }

        if(solve(s) == false) {
            cout << "<" << s << "> is not acceptable.\n";
            continue;
        }

        if(s.size() >= 3 && solve1(s) == false) {
            cout << "<" << s << "> is not acceptable.\n";
            continue;
        }

        if(s.size() >= 2 && solve2(s) == false) {
            cout << "<" << s << "> is not acceptable.\n";
            continue;
        }

        cout << "<" << s << "> is acceptable.\n";
    }
}