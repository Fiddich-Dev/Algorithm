#include <bits/stdc++.h>
using namespace std;

int n;
string temp;
// vector<int> ret;
vector<string> ret;

// 숫자를 문자로 추출
void solve(string s) {
    string a = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            a += s[i];
        }
        else {
            if(a.size()) {
                ret.push_back(a);
                a = "";
            }
        }
    }
    if(a.size()) {
        ret.push_back(a);
    }
}

// 앞에 0제거
string del(string s) {
    int a = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '0') {
            a = i;
            break;
        }
        else {
            a = -1;
        }
    }
    if(a == -1) {
        return "0";
    }

    return s.substr(a);
}

// 정렬
bool compare(string s1, string s2) {
    if(s1.size() == s2.size()) {
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == s2[i]) {
                continue;
            }
            return s1[i] < s2[i];
        }
    }
    return s1.size() < s2.size();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        solve(temp);
    }

    for(int i = 0; i < ret.size(); i++) {
        ret[i] = del(ret[i]);
    }

    sort(ret.begin(), ret.end(), compare);
    
    for(string s : ret) {
        cout << s << "\n";
    }

}