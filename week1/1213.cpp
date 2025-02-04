#include <bits/stdc++.h>
using namespace std;

string s;
int a[26];
string ret;
vector<int> v0;
vector<int> v1;


// 문자열 반쪽 만들기
string solve() {
    string x = "";
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < a[i]/2; j++) {
            x += i + 'A';
        }
    }
    return x;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        a[s[i] - 'A']++;
    }

    // 홀수개인 알파벳의 개수 찾기
    for(int i = 0; i < 26; i++) {
        if(a[i] % 2 == 1) {
            // 홀수개인 알파벳의 인덱스
            v1.push_back(i);
        }
        else if(a[i] != 0 && a[i] % 2 == 0) {
            // 짝수개인 알파벳의 인덱스
            v0.push_back(i);
        }
    }
    // 가능할때
    if(s.size() % 2 == 0 && v1.size() == 0) {
        ret = solve();
        string temp = ret;
        reverse(temp.begin(), temp.end());
        cout << ret + temp << "\n";
    }
    else if(s.size() % 2 == 1 && v1.size() == 1) {
        ret = solve();
        string temp = ret;
        reverse(temp.begin(), temp.end());
        cout << ret + char(v1[0] + 'A') + temp << "\n";
    }
    // 불가능할때
    else {
        cout << "I'm Sorry Hansoo\n";
    }
}