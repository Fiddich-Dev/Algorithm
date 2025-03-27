#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
// 성냥의 개수로 만들수 있는 숫자의 최솟값
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

string solveMax(int num) {
    string ret = "";
    if(num & 1) {
        num -= 3;
        ret += "7";
    }
    for(int i = 0; i < num/2; i++) {
        ret += "1";
    }
    return ret;
}

int main() {
    cin >> t;

    fill(dp, dp + 104, MAX_STR);
    dp[0] = "";

    for(int i = 2; i < 104; i++) {
        for(int j = 0; j <= 9; j++) {
            if(i - a[j] < 0 || i - a[j] == 1) {
                continue;
            }
            if(j == 0 && dp[i - a[j]] == "") {
                continue;
            }
            dp[i] = minStr(dp[i], dp[i - a[j]] + to_string(j));
        }
    }

    while(t--) {
        cin >> n;
        
        
        cout << dp[n] << " " << solveMax(n) << "\n";
    }
}