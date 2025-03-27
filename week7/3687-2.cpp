#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[104];
const string MAX_STR = "111111111111111111111111111111111111111111111111111";


string minStr(string a, string b) {
    if(a.size() == b.size()) {
        return a < b ? a : b;
    }
    if(a.size() < b.size()) {
        return a;
    }
    else {
        return b;
    }
}

string solveMin(int num) {
    if(num == 0) {
        return "";
    }

    string &ret = dp[num];
    if(ret != MAX_STR) {
        return ret;
    }

    for(int i = 0; i <= 9; i++) {
        if(num - a[i] == 1 || num - a[i] < 0) {
            continue;
        }
        if(num == n && i == 0) {
            continue;
        }
        ret = minStr(ret, to_string(i) + solveMin(num - a[i]));
    }
    return ret;
}

string solveMax(int num) {
    string ret = "";
    if(num & 1) {
        num -= 3;
        ret += "7";
    }
    for(int i = 0; i < n/2; i++) {
        ret += "1";
    }
    return ret;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        
        fill(&dp[0], &dp[0] + 104, MAX_STR);
        cout << solveMin(n) << " " << solveMax(n) << "\n";
    }
}