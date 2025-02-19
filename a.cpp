#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct A {
    int a;
    int b;
    int c;
};

int n;
int first_atk;
int temp1, temp2, temp3;
vector<A> room;
ll ret = 1e18;

bool check(ll mid) {
    ll now_atk = first_atk;
    ll nowHP = mid;

    for(int i = 0; i < n; i++) {
        if(room[i].a == 1) {
            ll attackCnt = room[i].c / now_atk;
            if(room[i].c % now_atk) {
                attackCnt++;
            }
            nowHP -= room[i].b * (attackCnt - 1);
            if(nowHP <= 0) {
                return false;
            }
        }
        else {
            nowHP += room[i].c;
            if(nowHP > mid) {
                nowHP = mid;
            }
            now_atk += room[i].b;
        }
    }
    return true;
}

int main() {
    cin >> n >> first_atk;
    for(int i = 0; i < n; i++) {
        cin >> temp1 >> temp2 >> temp3;
        room.push_back({temp1, temp2, temp3});
    }

    ll l = 1;
    ll r = 1e18;
    ll mid;

    while(l <= r) {
        mid = (l + r) / 2;
        if(check(mid) == true) {
            r = mid - 1;
            ret = min(ret, mid);
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret << "\n";
}