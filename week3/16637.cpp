#include <bits/stdc++.h>
using namespace std;

int n;
string s;
// 숫자
vector<char> v1;
// 연산자
vector<char> v2;
int result = -1e9;

int op(int a, char o, int b) {
    if(o == '+') {
        return a + b;
    }
    else if(o == '-') {
        return a - b;
    }
    else {
        return a * b;
    }
}

void go(int now, int ret) {
    if(now >= v2.size()) {
        result = max(result, ret);
        return;
    }

    int temp = op(ret, v2[now], v1[now+1] - '0');
    go(now + 1, temp);

    if(now + 1 < v2.size()) {
        temp = op(v1[now+1] - '0', v2[now+1], v1[now+2] - '0');
        temp = op(ret, v2[now], temp);
        go(now + 2, temp);
    }
}

int main() {
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            v1.push_back(s[i]);
        }
        else {
            v2.push_back(s[i]);
        }
    }

    go(0, v1[0] - '0');

    cout << result << "\n"; 
}