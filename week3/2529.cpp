#include <bits/stdc++.h>
using namespace std;

int k;
char temp;
vector<char> v;
int visited[10];

string mx = "";
string mn = "9999999999";

bool check(int a, char c, int b) {
    if(c == '<') {
        return a < b;
    }
    else {
        return a > b;
    }
}

void go(vector<int> b) {
    if(b.size() == k+1) {
        // 최대, 최소 갱신
        string s = "";
        for(int i : b) {
            s += to_string(i);
        }

        mx = max(mx, s);
        mn = min(mn, s);

        return;
    }

    for(int i = 0; i <= 9; i++) {
        // b가 비어있으면 추가하고 재귀
        if(b.size() == 0) {
            visited[i] = 1;
            b.push_back(i);

            go(b);

            visited[i] = 0;
            b.pop_back();
        }
        // b가 비어있지 않고 다음 수를 사용한 적이 없고 부등호가 맞을떄
        else {
            if(visited[i] == 0 && check(b[b.size() - 1], v[b.size() - 1], i)) {
                visited[i] = 1;
                b.push_back(i);

                go(b);

                visited[i] = 0;
                b.pop_back();
            }
        }
    }

}

int main() {
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> temp;
    go(temp);

    cout << mx << "\n";
    cout << mn << "\n";
}